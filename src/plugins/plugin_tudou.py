#!/usr/bin/python

from lplayer_utils import list_links, convert_to_utf8
import re
import lplayer
try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET

#hosts
hosts = ('www.tudou.com',)

#parse videos
def parse(url, options):
    if url.startswith('http://www.tudou.com/listplay/') or url.startswith('http://www.tudou.com/programs/view/'):  #single video
        parser.feed(url, options)
        
    else:  #wrong url
        lplayer.warn('Please input a valid tudou url.')
    
#parse videos
iid_re = re.compile(r'"pt":(\d+)[^}]+"k":(\d+)')
name_re = re.compile(r'kw:\s*[\'"]([^\'"]+)')

class Parser(object):
    def feed(self, url, options):
        lplayer.get_url(url, self.parse_cb, options)
        
    def parse_cb(self, page, options):
        #page = content.decode('GBK').encode('UTF-8')
        page = convert_to_utf8(page)
        name_match = name_re.search(page)
        if not name_match:
            lplayer.warn('Cannot get video name.')
            return
        self.name = name_match.group(1)
        
        if options & lplayer.OPT_QL_SUPER:
            i = 5
        elif options & lplayer.OPT_QL_HIGH:
            i = 3
        else:
            i = 2
        vlist = [None] * 6
        iid_match = iid_re.search(page)
        while iid_match:
            (pt, k) = iid_match.group(1, 2)
            pt = int(pt)
            if pt < 6:
                if vlist[pt] == None:
                    vlist[pt] = []
                vlist[pt].append(k)
            iid_match = iid_re.search(page, iid_match.end(0))
        while i >= 0:
            if vlist[i]:
                self.keys = vlist[i]
                self.result = []
                url = 'http://v2.tudou.com/f?id=' + self.keys[0]
                lplayer.get_url(url, self.parse_keys, options)
                return
            i -= 1
        lplayer.warn('Fail!')
    
    def parse_keys(self, content, options):
        root = ET.fromstring(content)
        i = len(self.result) / 2
        self.result.append('%s_%i.f4v' % (self.name, i))
        self.result.append(root.text)
        i += 1
        if i < len(self.keys):
            url = 'http://v2.tudou.com/f?id=' + self.keys[i]
            lplayer.get_url(url, self.parse_keys, options)
        elif options & lplayer.OPT_DOWNLOAD:
            lplayer.download(self.result, self.name + '.f4v')
        else:
            lplayer.play(self.result)
parser = Parser()

