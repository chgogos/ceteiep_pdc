# https://www.cs.swarthmore.edu/~newhall/unixhelp/javamakefiles.html

JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    HelloRunnable.java \
	HelloThread.java \
	HelloAnonymous.java \
	HelloLambdas.java \
	SleepMessages.java \
	SimpleThreads.java \
	Counter.java \
	CounterExample.java \
	SynchronizedCounter.java \
	SynchronizedCounterExample.java \
	SynchronizedCounter2.java \
	SynchronizedCounter2Example.java \
	MsLunch.java \
	MsLunchExample.java \
	Deadlock.java \
	Drop.java \
	Producer.java \
	Consumer.java \
	ProducerConsumerExample.java \
	Producer2.java \
	Consumer2.java \
	ProducerConsumerBlockingQueueExample.java \
	SynchronizedRGB.java \
	ImmutableRGB.java \
	RGBExample.java \
	Safelock.java \
	AtomicCounter.java \
	AtomicCounterExample.java

default: classes

classes: $(CLASSES:.java=.class)

# HelloRunnable.java
run1: 
	java HelloRunnable

# HelloThread.java
run2: 
	java HelloThread

# HelloAnonymous.java
run3: 
	java HelloAnonymous

# HelloLambdas.java
run4: 
	java HelloLambdas

# SleepMessages.java
run5: 
	java SleepMessages

# SimpleThreads.java
run6: 
	java SimpleThreads

# Counter.java, CounterExample.java
run7: 
	java CounterExample

# SynchronizedCounter.java, SynchronizedCounterExample.java
run8: 
	java SynchronizedCounterExample

# SynchronizedCounter2.java, SynchronizedCounter2Example.java
run9: 
	java SynchronizedCounter2Example

# MsLunch.java, MsLunchExample.java
run10: 
	java MsLunchExample

# Deadlock.java
run11:
	java Deadlock

# Drop.java, Producer.java, Consumer.java, ProducerConsumerExample.java
run12:
	java ProducerConsumerExample

# Producer2.java, Consumer2.java, ProducerConsumerBlockingQueueExample.java
run13:
	java ProducerConsumerBlockingQueueExample

# RGBExample.java, SynchronizedRGB.java, ImmutableRGB.java
run14:
	java RGBExample

#  Safelock.java
run15:
	java Safelock

# AtomicCounter.java, AtomicCounterExample.java
run16: 
	java AtomicCounterExample

clean:
	$(RM) *.class
