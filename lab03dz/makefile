# https://www.cs.swarthmore.edu/~newhall/unixhelp/javamakefiles.html

JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $*.java

CLASSES = \
    DataRace.java \
	DataRaceVolatileFlag.java \
	Deadlock.java \
	NoDeadlock.java

default: classes 

classes: $(CLASSES:.java=.class)

run1:
	java DataRace

run2:
	java DataRaceVolatileFlag

run3:
	java Deadlock

run4:
	java NoDeadlock

clean:
	$(RM) *.class
