generate:
	java -Xmx500M -cp "/usr/local/lib/antlr-4.5-complete.jar:$CLASSPATH" org.antlr.v4.Tool Fabula.g4 -visitor
	javac Fabula*.java
	echo 'Done!'
	java org.antlr.v4.runtime.misc.TestRig Fabula prog -gui

build:
	javac *.java
run:
	java Source
