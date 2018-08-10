https://github.com/go-lang-plugin-org/go-lang-idea-plugin/issues/2897
GO_PLUGIN_BIN=$1


mkdir /tmp/foo
cd /tmp/foo
unzip ~/Downloads/$GO_PLUGIN_BIN
mkdir intellij-go-0.13.1947.until-build-172
cd intellij-go-0.13.1947.until-build-172/
unzip ../Go/lib/intellij-go-0.13.1947.jar
vim META-INF/plugin.xml # edit for the above
rm ../Go/lib/intellij-go-0.13.1947.jar
zip -r ../Go/lib/intellij-go-0.13.1947.jar .
cd ../
zip -r Go.zip Go
