Name:           lplayer
Version:        2.9.0 
Release:        1%{?dist}
Summary:        The mplayer based Acfun media player

License:        GPLv2+
URL:            http://ldeteam.tk
Source0:        %{name}.tar.gz

BuildRequires:  qt5-qtbase-gui, qt5-qtwebkit-devel, gcc-c++, pkgconfig, python-devel, qt5-qtxmlpatterns-devel, cmake
Requires:       qt5-qtbase, qt5-qtbase-gui, qt5-qtwebkit, qt5-qtxmlpatterns, python, mplayer, python3

%description
Free and open source, cross-platform, mplayer based multimedia player. Qt 5.


%prep
%setup -q -n %{name}


%build
cmake . && make


%install
make DESTDIR=$RPM_BUILD_ROOT install


%define __os_install_post %{!?nil}



%files
%doc
%{_bindir}/*
%{_datadir}/applications/*
%{_datadir}/lplayer/*
%{_datadir}/Icons/*


%changelog
* Tue Sep 1 2015 Zhuoyi Xu (LDE Team) <xzy476386434@vip.qq.com> - 2.9.0
- Fix dput Upload Error (#20)
