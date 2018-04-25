# https://www.cs.swarthmore.edu/~newhall/unixhelp/javamakefiles.html

JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    Exercise01Runnable.java \
    Exercise01Extends.java \
    Exercise01Anonymous.java \
    Exercise01Lambda.java \
	Exercise02Synchronized.java \
	Exercise02Futures.java \
	Exercise02Lock.java \
	Exercise03Synchronized.java \
	Exercise03Futures.java \
	Exercise04Main.java \
	Exercise04Producer.java \
	Exercise04Consumer.java \
	Exercise05Swing.java \
	Exercise05Fx.java \
	Exercise06TUI.java \
	Exercise07Extends.java \
	Exercise07Runnable.java \
	Exercise07Lambda.java \
	Exercise08Join.java \
	Exercise08Synchronized.java \
	Exercise08Futures.java \
	Exercise08Lock.java 

default: classes exercise06gui

classes: $(CLASSES:.java=.class)

exercise06gui: Exercise06GUI.java
	$(JC) $(JFLAGS) -cp commons-lang3-3.5.jar Exercise06GUI.java

run1a:
	java Exercise01Runnable

run1b:
	java Exercise01Extends

run1c:
	java Exercise01Anonymous

run1d:
	java Exercise01Lambda

run2a:
	java Exercise02Synchronized

run2b:
	java Exercise02Futures

run2c:
	java Exercise02Lock

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

run7a: 
	java -ea Exercise07Extends

run7b: 
	java -ea Exercise07Runnable

run7c: 
	java -ea Exercise07Lambda

run8a:
	java Exercise08Join

run8b:
	java Exercise08Synchronized

run8c:
	java Exercise08Futures

run8d:
	java Exercise08Lock

# on windows
# run6b: 
# 	java -cp .;commons-lang3-3.5.jar Exercise06GUI

clean:
	$(RM) *.class

# on windows
# clean:
# 	del *.class