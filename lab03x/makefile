# https://www.cs.swarthmore.edu/~newhall/unixhelp/javamakefiles.html

JFLAGS = -g 
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    Exercise01Runnables.java \
    Exercise01Extends.java \
    Exercise01Anonymous.java \
    Exercise01Lambdas.java \
	Exercise02Synchronized.java \
	Exercise02Futures.java \
	Exercise03Synchronized.java \
	Exercise03Futures.java \
	Exercise04Main.java \
	Exercise04Producer.java \
	Exercise04Consumer.java \
	Exercise05Swing.java \
	Exercise05Fx.java \
	Exercise06TUI.java 

default: classes exercise06gui

classes: $(CLASSES:.java=.class)

exercise06gui: Exercise06GUI.java
	$(JC) $(JFLAGS) -cp commons-lang3-3.5.jar Exercise06GUI.java

run1a:
	java Exercise01Runnables

run1b:
	java Exercise01Extends

run1c:
	java Exercise01Anonymous

run1d:
	java Exercise01Lambdas

run2a:
	java Exercise02Synchronized

run2b:
	java Exercise02Futures

run3a:
	java Exercise03Synchronized

run3b:
	java Exercise03Futures

run4: 
	java Exercise04Main

run5a: 
	java Exercise05Swing

run5b: 
	java Exercise05Fx

run6a: 
	java Exercise06TUI

run6b: 
	java -cp .:commons-lang3-3.5.jar Exercise06GUI

# windows
# run6b: 
# 	java -cp .;commons-lang3-3.5.jar Exercise06GUI

clean:
	$(RM) *.class

# windows
# clean:
# 	del *.class