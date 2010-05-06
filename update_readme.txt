~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Achtung:
Framework-Update f�r Assignment A2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Datum:
7. April 2010
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Grund f�r das Update:
Fehler in der Datei "rno_lib.a" bei der
Berechung der LFSR-Bits im Falle einer
Matrikelnummer "3 mod 4".
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
�nderungen im Framework:

- Die Datei "test/rno_lib.a" wurde durch die
      Datei "test/rno_lib_neu.a" ersetzt.

- Die Datei "Makefile" wurde in einer Zeile ver�ndert:
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

Die Datei hei�t "rno_A2_update.zip".

Wir bitten Sie, ab sofort dieses neue Framework
f�r Ihre Arbeit am Assignment A2 zu verwenden.


Sollten Sie Ihre Aufgabe bereits gemacht oder sogar
abgegeben haben:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Die �nderung betrifft nur Matrikelnummern, welche
"3 mod 4" ergeben. Sollte dies bei Ihnen nicht der
Fall sein, dann k�nnen Sie das Update ignorieren.


Wen betrifft das im Besonderen?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Wenn Sie eine Matrikelnummer haben, welche
"3 mod 4" ergibt, dann m�ssen Sie diese
neue Version unbedingt verwenden; nur dann stimmt
auch das vom Framework verwendete
Linear Feedback Shift Register mit dem
in der Aufgabenstellung geforderten �berein.


Wozu ein Update?
~~~~~~~~~~~~~~~~
Bei der nunmehr "alten" Version haben wir
einen Fehler entdeckt. Dieser Fehler wurde
unter aktiver Mitarbeit von Studierenden
entdeckt. Daf�r bedanken wir uns besonders.
Das in der "alten" Version verwendete
Linear Feedback Shift Register f�r die
Variante "3 mod 4" stimmt nicht mit dem
in der Aufgabenstellung geforderten �berein.


Was ist beim Update anders?
~~~~~~~~~~~~~~~~~~~~~~~~~~~
Wir haben die Bibliotheksdatei "librno_lib.a"
im Verzeichnis "test" ausgebessert. Diese
hei�t jetzt "librno_lib_neu.a" und wird im
Makefile auch verwendet.


Kann man die �nderung auch manuell vornehmen?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ja. Sie m�ssen
die alte Bibliotheksdatei "librno_lib.a" durch
die neue Bibliotheksdatei "librno_lib_neu.a"
ersetzen und die entsprechende Zeile im Makefile
ver�ndern:
"LD_LIBS = -lrno_lib_neu".

Sie finden die Bibliotheksdatei im
Unterverzeichnis "test".


Was kann man daraus lernen?
~~~~~~~~~~~~~~~~~~~~~~~~~~~
Das Vermeiden von Fehlern beim Erstellen
von Software ist grunds�tzlich schwierig.
Und solche Fehler k�nnen zu unangenehmen
Situationen f�hren. Speziell dann, wenn viele
Anwender dieser Software davon betroffen sind.

Im Falle hier haben die Lehrer Software
bereit gestellt, um es den Studierenden
einfacher zu machen, ihre L�sungen auf
Richtigkeit zu �berpr�fen. Ein Serviceangebot
sozusagen. Dieser positive Serviceaspekt
steht dem negativen Aspekt gegen�ber,
dass das Service selbst grunds�tzlich
fehleranf�llig ist.

Diese Erkl�rung soll nicht dazu dienen,
das Vorhandensein von Fehlern in Software
zu entschuldigen. Sie soll jedoch dazu dienen,
dass Sie erfahren und lernen, damit auf
professionelle Weise umzugehen. Eine
M�glichkeit daf�r besteht in der geeigneten
Kommunikation von entdeckten Problemen.
Zumindest ein/e KollegIn von Ihnen hat das
gemacht. Wir alle bedanken uns f�r den
"zweckdienlichen" Hinweis. Wir Lehrer denken,
dass er/sie mit dieser Dienstleistung einen
Bonus verdient hat.


Michael Hutter
Karl C. Posch
Horst Possegger 