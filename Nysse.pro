TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
        Game \
        StatisticsUnitTest

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib
