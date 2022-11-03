---
name: Checkliste Praktikum 4
about: Template zur Bewertung des Praktikums

---

# CI / CD Arbeitszyklus
- [ ] Das Projekt lässt sich in Jenkins erfolgreich bauen und erzeugt entsprechende Statistiken
- [ ] Die Jenkins-Historie zeigt, dass alle Teammitglieder  den Code zuerst lokal zum Laufen bringen und erst dann das Ergebnis veröffentlichen (d.h. es gibt nur wenige fehlerhafte Builds)
- [ ] Die Git-Statistik in Jenkins zeigt, dass jedes Teammitglied angemessen viel Quellcode bearbeitet hat
- [ ] Es gibt keine neuen Fehler von CppCheck, Compiler oder Doxygen (z.B. wegen neuer Methoden durch Refactoring)

# Tests
- [ ] Der Trend der Testergebnisse in Jenkins zeigt eine deutliche Zunahme der Tests 
- [ ] Die Testlaufzeit im Jenkins liegt bei wenigen Sekunden (der Turbo-Modus ist aktiv) 
- [ ] Der Report "Code Coverage" in Jenkins zeigt (ganz oben), dass es ungefähr so viele Tests wie Funktionen gibt. Wegen der beiden (noch) ausgenommenen Klassen sind es evtl. weniger als 100%.
- [ ] Der Test Result Analyzer zeigt (wenn man das kleine + anklickt), dass es neue Tests zu jeder Klasse gibt 
- [ ] Die Tests enthalten sinnvolle ASSERT- oder EXPECT-Anweisungen (Stichprobe)?

# Bemerkungen / Hinweise
- 

# Gesamtergebnis (Ampelskala)
- 