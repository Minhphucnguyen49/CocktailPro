---
name: Checkliste Praktikum 3
about: Template zur Bewertung des Praktikums

---

# CI / CD Arbeitszyklus
- [ ] Das Projekt lässt sich in Jenkins erfolgreich bauen und erzeugt entsprechende Statistiken
- [ ] Die Jenkins-Historie zeigt, dass jedes Teammitglied sein Ergebnis (durch einen Jenkins-Build) nach dem Veröffentlichen geprüft hat
- [ ] Die Jenkins-Historie zeigt, dass alle Teammitglieder  den Code zuerst lokal zum Laufen bringen und erst dann das Ergebnis veröffentlichen (d.h. es gibt nur wenige fehlerhafte Builds)
- [ ] Die Git-Statistik in Jenkins zeigt, dass jedes Teammitglied angemessen viel Quellcode bearbeitet hat
- [ ] Es gibt keine neuen Fehler von CppCheck, Compiler oder Doxygen (z.B. wegen neuer Methoden durch Refactoring)

# Refactoring
- [ ] Die CCCC-Statistik in Jenkins enthält keine gelben oder roten Einträge mehr
- [ ] Stichprobe: Die Magic Number 1000 in der Datei Timer.cpp wurde durch Refactoring ersetzt
- [ ] Stichprobe: In AvailableIngredients.cpp Zeile 15 wurde der Dateiname "zutaten.txt" extrahiert
- [ ] Der Konstruktor von RecipeBook wurde in mehrere Methoden aufgeteilt
- [ ] Der Konstruktor von MixableRecipeBook wurde in mehrere Methoden aufgeteilt

# Bug Fixing (Ausführung der Binaries)
- [ ] Cocktail Planters Punch wird nicht mehr angeboten
- [ ] Martini J.B. wird jetzt angeboten und kann gemischt werden 
- [ ] Es werden nur noch benutzte Geräte gereinigt
- [ ] Die Eingabe 0 wird als ungültig erkannt

# Bemerkungen / Hinweise
- 

# Gesamtergebnis (Ampelskala)
- 