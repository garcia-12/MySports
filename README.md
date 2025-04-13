```markdown
# 🏅 MySport – Athletenverwaltung in C++ mit Stil und Struktur

Sport trifft Code – dieses Projekt ist eine objektorientierte Simulation eines sportlichen Verwaltungssystems 🧠⚽  
Ob Läufer, Schwimmer oder andere Athleten: Mit MySport kannst du Sportler einfach modellieren und verwalten.

## 🚀 Was macht dieses Projekt?

Das Ziel dieses Projekts ist es, verschiedene Arten von Athleten zu verwalten, ihre Daten zu speichern und durch polymorphe Strukturen zu erweitern.  
Es zeigt die Kraft von Vererbung, Abstraktion und sauberem Softwaredesign mit C++.

## 🧠 Features

- Verwaltung verschiedener Athletentypen (z. B. Läufer, Schwimmer)  
- Ausgabe individueller Eigenschaften jedes Athleten  
- Erweiterbare Klassenstruktur  
- Beispielhafte Nutzung von Vererbung und Polymorphie

## 🛠️ Projektstruktur

```
MySport/
├── main.cpp              # Einstiegspunkt
├── athlete.cpp/.h        # Abstrakte Basisklasse "Athlete"
├── runner.cpp/.h         # Spezialisierung: Läufer
├── swimmer.cpp           # Spezialisierung: Schwimmer
├── mysports.cpp/.h       # Zentrale Verwaltungslogik
├── CMakeLists.txt        # Build-Konfiguration mit CMake
```

## 🧪 Kompilierung & Ausführung

### Voraussetzungen

- C++ Compiler (`g++`, `clang++`, etc.)  
- [CMake](https://cmake.org/) installiert

### Schritte

cd MySport
mkdir build && cd build
cmake ..
make
./MySport  # Oder der generierte Binary-Name


## 👨‍🎓 Über mich

Ich bin Informatikstudent mit Fokus auf C++ und React.js, leidenschaftlich kreativ im Code – und stets bereit, Neues zu lernen.  
Dieses Projekt spiegelt mein Interesse an Struktur, Modularität und zukunftsgerichteter Softwareentwicklung wider 🧩🚀

## 🏋️ Erweiterungsideen

- Weitere Sportarten (z. B. Radsport, Triathlon)  
- Trainingseinheiten & Leistungsdaten  
- GUI zur Visualisierung  
- Datenexport im JSON/CSV-Format

„Code ist wie Training – je mehr Struktur, desto mehr Leistung.“
