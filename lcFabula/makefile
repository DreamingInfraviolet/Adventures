build:
	java -Xmx500M -cp "/usr/local/lib/antlr-4.5-complete.jar:$CLASSPATH" org.antlr.v4.Tool Fabula.g4
	javac Fabula*.java
	echo 'Done!'
	java org.antlr.v4.runtime.misc.TestRig Fabula prog -gui

run:
	java org.antlr.v4.runtime.misc.TestRig Fabula prog -gui
