@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\qt\6.2.0\mingw81_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\qt\6.2.0\mingw81_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\qt\6.2.0\mingw81_64\plugins
)
%*
EndLocal
