###############################################################
# Version        1.2.0
# Datum          06.10.2015
# Autor          Jens-Peter Akelbein
# Beschreibung   Makefile fuer Cockteilpro-Projekt, enthaelt
#                die zur Aufgabenstellung Qualitätssicherung
#                notwendigen Aufrufe 
###############################################################


#############################################
# Variablendefinition und Tools
#############################################
CC = g++
CCCC = "cccc"

# Compiler- und Linkerflags
# --coverage Option erzeugt Code Coverage Daten
# -g         Option erzeugt Debuginformationen)
CCFLAGS = --coverage -g

# Log-Dateiname fuer Code Coverage Analysis
COVLOG = coverage.log
# Option fuer Coverage Analyse ohne Branch Analysis
COVFLAGS = --directory .
# Option fuer HTML Report Generierung ohne Branch Analysis
HTMLFLAGS = 
# Flags fuer eine Analyse mit Branch Coverage (fuer Zweig-/Pfadueberdeckung)
# COVFLAGS = --rc lcov_branch_coverage=1
# HTMLFLAGS = --branch-coverage --rc lcov_branch_coverage=1

# Alle Quell- und Objektdateien
# >>>>>> Hier tragen Sie alle Quelldateien und die Objektdatei des Rezeptbuchs ein
FILES =  Main.cpp File1.cpp File2.cpp File3.cpp \
         File4.cpp Rezeptbuch_g++_CASE_Ubuntu.o
# Name des ausfuehrbaren Programms
# >>>>>> Hier tragen Sie den Namen ihres ausführbaren Programms ein
EXEC = CocktailPro


#############################################
## >>>>>>>>> Erzeugung des Executables
#############################################

# Default target, wenn keine Angabe bei make gemacht wurde
all: $(EXEC)

# Regel fuer das Executable
$(EXEC): ALWAYS
	$(CC) $(CCFLAGS) $(FILES) -o $(EXEC)


#############################################
# >>>>>>> Coverage-Analyse
# Vorbereitung: Erzeugen Sie instrumentierten Code (siehe Erzeugung des Executables)
# 1. make report_start
# 2. Executable laufen lassen
# 3. make report
# 4. Im browser index.html oeffnen
# Weitere Programmlaeufe: jeweils Schritt 2...4
#
# Die Statistik zählt das Durchlaufen jeder Codezeile kumulativ
# auch bei mehrmaligen Aufrufen des zu untersuchenden Programms.
# Zum Löschen/Zuruecksetzen des Reports rufen Sie folgendes auf:
# make report_zero
#############################################
# Starte Code Coverage-Analyse, erzeuge hierzu die noetigen Dateien
# (Hinweis: weiterleiten mittels >> statt > auf der Kommandozeile fuegt den Inhalt an
# und erzeugt ein Log statt die Datei immer neu zu schreiben
report_start: $(EXEC)
	echo "--->START" >> $(COVLOG)
	lcov --no-external --capture --initial $(COVFLAGS) --directory . --output-file ./main_base.info >> $(COVLOG)

# Erzeuge aus der derzeitigen Ausfuehrungsstatistik einen Report
# ACHTUNG: Testprogramm muss nach einem Build oder nach dem Zuruecksetzen der Zaehler mindestens einmal aufgerufen worden sein!!!
# 1. Halte den derzeitigen Stand fest (capture) in main_test.info
# 2. Erzeuge das Delta zwischen den Stand bei start und jetzt in main_total.info
# 3. Entferne unnoetige Informationen aus dem info-File und speicher dies in main_filtered.info
# 4. Erzeuge einen Report im HTML-Formet, danach kann in einem Browser mit index.html als Ueberblick begonnen werden
report:
	echo "--->REPORT 1. Schritt" >> $(COVLOG)
	lcov $(COVFLAGS) --no-external --capture --output-file ./main_test.info >> $(COVLOG)
	echo "--->REPORT 2. Schritt" >> $(COVLOG)
	lcov $(COVFLAGS) --add-tracefile ./main_base.info --add-tracefile ./main_test.info --output-file ./main_total.info >> $(COVLOG)
	echo "--->REPORT 3. Schritt" >> $(COVLOG)
	lcov $(COVFLAGS) --remove ./main_total.info '/usr/include/*' '/usr/lib/*' -o ./main_filtered.info >> $(COVLOG)
	echo "--->REPORT 4. Schritt" >> $(COVLOG)
	genhtml --prefix . --ignore-errors source ./main_filtered.info --legend --title "Report" \
	--function-coverage  $(HTMLFLAGS) --output-directory=. >> $(COVLOG)

# Loesche Dateien, die fuer den Coverage Report angelegt wurden (HTML-Report selbst bleibt erhalten)
report_clean: ALWAYS
	rm *.gcno *gcda *.info $(COVLOG)
	
# Loesche alle Counter, die fuer den Coverage Report angelegt wurden (Dateien bleiben erhalten)
report_zero: ALWAYS
	lcov --no-external --zerocounters --rc lcov_branch_coverage=1 --directory . --output-file ./main_test.info >> $(COVLOG)


#############################################
# >>>>>>>> Erzeuge Metriken
# 1. make metric_start
# 2. make metric
# 3. Im Browser metric/cccc.html oeffnen
# Nach Aenderungen des Quelltextes: Schritt 2
#
# Zum Loeschen der Metriken make metric_clean aufrufen
#############################################

# Erzeuge Verzeichnis, in dem die Analysedaten erzeugt werden (cccc.html als Start)
metric_start:
	mkdir metric

# Erzeuge die Metriken
metric: ALWAYS
	$(CCCC) --outdir=metric --db_outfile=metric.db $(FILES)

# Loesche die Metrikdaten und das Verzeichnis
metric_clean:
	rm -r metric

#############################################
# Automatische Ausfuehrung von Test Cases (statt manuellen Tests)
# Beispiele, wie Sie ihre Testcases definieren und automatisch laufen lassen können,
# statt die Eingaben manuell zu machen (Nachvollziehbarkeit von Testfällen!).
# 
# Der Inhalt der Daten TC1 etc. enthält in jeweils einer Zeile die Eingabe,
# die das Programm vom Nutzer erwartet.
#############################################

# Fuehre Testcases aus, die in den Datei TC1, TC2 enthalten sind (mittels Pipe wird der Dateiinhalt zur Programmeingabe)
tc1: ALWAYS
	$(EXEC) < TC1

tc2: ALWAYS
	$(EXEC) < TC2

tc3: ALWAYS
	$(EXEC) < TC3

#############################################
# Sonstiges
#############################################


# Target, was in Abhaengigkeiten sicherstellt, dass die Ausfuehrung durchgeführt wird
.PHONY ALWAYS:

#############################################
# Dokumentation
#############################################
#
# CCCC Project on Source Forge
# http://cccc.sourceforge.net/
# CCCC Download
# http://sourceforge.net/projects/cccc/
# CCCC USer Guide
# http://www.stderr.org/doc/cccc/CCCC%20User%20Guide.html
#
# GCOV Dokumentation (Teil der Linux-Entwicklungstools)
# http://www.linuxcommand.org/man_pages/gcov1.html
# http://www.fnal.gov/docs/products/gcc/v3_1/gcc.info,.Gcov.html
# Artikel über Arbeiten mit gcov
# berrendorf.inf.fh-bonn-rhein-sieg.de/lehre/ws0304/vups2/s1_gcov.pdf
#
# LCOV Frontend zu GCOV zum Erzeugen von HTML-Reports
# Download
# http://ltp.sourceforge.net/coverage/lcov.php
# README zur Installation
# http://ltp.sourceforge.net/coverage/lcov/readme.php
# Man-Page
# http://linux.die.net/man/1/lcov


