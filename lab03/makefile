# https://www.cs.swarthmore.edu/~newhall/unixhelp/javamakefiles.html

JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    HelloRunnable.java \
	HelloThread.java \
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

# 
run1: HelloRunnable.java
	java HelloRunnable

#
run2: HelloThread.java
	java HelloThread

#
run3: SleepMessages.java
	java SleepMessages

#
run4: SimpleThreads.java
	java SimpleThreads

# Counter.java, CounterExample.java
run5: CounterExample.java
	java CounterExample

# SynchronizedCounter.java, SynchronizedCounterExample.java
run6: SynchronizedCounterExample.java
	java SynchronizedCounterExample

# SynchronizedCounter2.java, SynchronizedCounter2Example.java
run7: SynchronizedCounter2Example.java
	java SynchronizedCounter2Example

# MsLunch.java, MsLunchExample.java
run8: MsLunchExample.java
	java MsLunchExample

# Deadlock.java
run9: Deadlock.java
	java Deadlock

# Drop.java, Producer.java, Consumer.java, ProducerConsumerExample.java
run10: ProducerConsumerExample.java
	java ProducerConsumerExample

# Producer2.java, Consumer2.java, ProducerConsumerBlockingQueueExample.java
run11: ProducerConsumerBlockingQueueExample.java
	java ProducerConsumerBlockingQueueExample

# RGBExample.java, SynchronizedRGB.java, ImmutableRGB.java
run12: RGBExample.java
	java RGBExample

# 
run13: Safelock.java
	java Safelock

# AtomicCounter.java, AtomicCounterExample.java
run14: AtomicCounterExample.java
	java AtomicCounterExample

clean:
	$(RM) *.class
