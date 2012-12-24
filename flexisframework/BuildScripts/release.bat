del FWProjects.zip
rmdir /S /Q flexisframework
svn export https://flexisframework.svn.sourceforge.net/svnroot/flexisframework
cd flexisframework/Framework
rmdir /S /Q Deprecated
cd ..\..
"C:\Program Files\7-Zip\7z.exe" a -r -tzip k:\release\FWprojects.zip K:\release\flexisframework\Framework\
"C:\Program Files\7-Zip\7z.exe" a -r -tzip k:\release\FWProjects.zip K:\release\flexisframework\WS_SAMPLES\






