#cmake file for project association
#author:>---LDE Team
#created:>--2015/08/29

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)                  
                                                        

PROJECT(lplayer)                                 

MESSAGE(STATUS "Project: lplayer")                       
MESSAGE(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")
                    

ADD_SUBDIRECTORY(src)                              
