# DZONE reference card - Java concurrency

Τα ακόλουθα παραδείγματα βασίζονται στο <https://dzone.com/refcardz/core-java-concurrency>

## Data race

* [DataRace.java](./DataRace.java)

```bash
java DataRace

```

## Χειρισμός data race με volatile μεταβλητή

* [DataRaceVolatileFlag.java](./DataRaceVolatileFlag.java)

```bash
java DataRaceVolatileFlag

```

## Αδιέξοδο (deadlock)

* [Deadlock.java](./Deadlock.java)

```bash
java Deadlock

Account1 1000 - Account2 1000
...
```

## Χειρισμός αδιεξόδου

Τα locks γίνονται με την ίδια σειρά οπότε δεν υπάρχει αδιέξοδο

* [NoDeadlock.java](./NoDeadlock.java)

```bash
java NoDeadlock

Account1 1000 - Account2 1000
Account1 900 - Account2 1100
```
