# DZONE reference card - Java concurrency

Τα ακόλουθα παραδείγματα βασίζονται στο <https://dzone.com/refcardz/core-java-concurrency>

## Data race

* [DataRace.java](./DataRace.java)

```bash
for i in {1..10}; do java DataRace; done

```

## Χειρισμός data race με volatile μεταβλητή

<https://www.javamex.com/tutorials/synchronization_volatile.shtml>

* [DataRaceVolatileFlag.java](./DataRaceVolatileFlag.java)

```bash
for i in {1..10}; do java DataRaceVolatileFlag; done

```

## Αδιέξοδο (deadlock)

* [Deadlock.java](./Deadlock.java)

```bash
java Deadlock

Account1 1000 - Account2 1000
<DEADLOCK>
```

## Χειρισμός αδιεξόδου

Τα locks γίνονται με την ίδια σειρά οπότε δεν υπάρχει αδιέξοδο

* [NoDeadlock.java](./NoDeadlock.java)

```bash
java NoDeadlock

Account1 1000 - Account2 1000
Account1 900 - Account2 1100
```
