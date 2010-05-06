~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Achtung:
Framework-Update für Assignment A2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Datum:
7. April 2010
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Grund für das Update:
Fehler in der Datei "rno_lib.a" bei der
Berechung der LFSR-Bits im Falle einer
Matrikelnummer "3 mod 4".
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Änderungen im Framework:

- Die Datei "test/rno_lib.a" wurde durch die
      Datei "test/rno_lib_neu.a" ersetzt.

- Die Datei "Makefile" wurde in einer Zeile verändert:
      Statt der Zeile
          "LD_LIBS = -lrno_lib"
      steht jetzt die Zeile
          "LD_LIBS = -lrno_lib_neu"
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Liebe RNO-StudentInnen,


Sie finden im RNO-Web

http://www.iaik.tugraz.at/content/teaching/bachelor_courses/rechnernetze_und_organisation/downloads/

zu Assignment A2 ein Update zum Framework
"RNO10_KU - Assignment A2 Framework" zum Runterladen.

Die Datei heißt "rno_A2_update.zip".

Wir bitten Sie, ab sofort dieses neue Framework
für Ihre Arbeit am Assignment A2 zu verwenden.


Sollten Sie Ihre Aufgabe bereits gemacht oder sogar
abgegeben haben:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Die Änderung betrifft nur Matrikelnummern, welche
"3 mod 4" ergeben. Sollte dies bei Ihnen nicht der
Fall sein, dann können Sie das Update ignorieren.


Wen betrifft das im Besonderen?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Wenn Sie eine Matrikelnummer haben, welche
"3 mod 4" ergibt, dann müssen Sie diese
neue Version unbedingt verwenden; nur dann stimmt
auch das vom Framework verwendete
Linear Feedback Shift Register mit dem
in der Aufgabenstellung geforderten überein.


Wozu ein Update?
~~~~~~~~~~~~~~~~
Bei der nunmehr "alten" Version haben wir
einen Fehler entdeckt. Dieser Fehler wurde
unter aktiver Mitarbeit von Studierenden
entdeckt. Dafür bedanken wir uns besonders.
Das in der "alten" Version verwendete
Linear Feedback Shift Register für die
Variante "3 mod 4" stimmt nicht mit dem
in der Aufgabenstellung geforderten überein.


Was ist beim Update anders?
~~~~~~~~~~~~~~~~~~~~~~~~~~~
Wir haben die Bibliotheksdatei "librno_lib.a"
im Verzeichnis "test" ausgebessert. Diese
heißt jetzt "librno_lib_neu.a" und wird im
Makefile auch verwendet.


Kann man die Änderung auch manuell vornehmen?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ja. Sie müssen
die alte Bibliotheksdatei "librno_lib.a" durch
die neue Bibliotheksdatei "librno_lib_neu.a"
ersetzen und die entsprechende Zeile im Makefile
verändern:
"LD_LIBS = -lrno_lib_neu".

Sie finden die Bibliotheksdatei im
Unterverzeichnis "test".


Was kann man daraus lernen?
~~~~~~~~~~~~~~~~~~~~~~~~~~~
Das Vermeiden von Fehlern beim Erstellen
von Software ist grundsätzlich schwierig.
Und solche Fehler können zu unangenehmen
Situationen führen. Speziell dann, wenn viele
Anwender dieser Software davon betroffen sind.

Im Falle hier haben die Lehrer Software
bereit gestellt, um es den Studierenden
einfacher zu machen, ihre Lösungen auf
Richtigkeit zu überprüfen. Ein Serviceangebot
sozusagen. Dieser positive Serviceaspekt
steht dem negativen Aspekt gegenüber,
dass das Service selbst grundsätzlich
fehleranfällig ist.

Diese Erklärung soll nicht dazu dienen,
das Vorhandensein von Fehlern in Software
zu entschuldigen. Sie soll jedoch dazu dienen,
dass Sie erfahren und lernen, damit auf
professionelle Weise umzugehen. Eine
Möglichkeit dafür besteht in der geeigneten
Kommunikation von entdeckten Problemen.
Zumindest ein/e KollegIn von Ihnen hat das
gemacht. Wir alle bedanken uns für den
"zweckdienlichen" Hinweis. Wir Lehrer denken,
dass er/sie mit dieser Dienstleistung einen
Bonus verdient hat.


Michael Hutter
Karl C. Posch
Horst Possegger 