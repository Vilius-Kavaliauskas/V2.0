# V1.0
Atlikti darbai:
# V0.1.1
1) Sukurta struktūra "Studentas"
2) Sukurta void f-ja nuskaitymui "Input"
3) Sukurta void f-ja išrašymui "Output"
4) Galutinis rezultatas skaičiuojamas pagal vidurkį
# V0.1.2
1) Sukurta double f-ja "Balas", priklausomai nuo vartotojo noro skaičiuojanti galutinius balus pagal medianą arba pagal vidurkį
2) Sukurta void f-ja "Rikiavimas". Naudojama tik tuo atveju, jei vartotojas nori sužinoti medianinius įverčius
# V0.1.3
1) Programa pritakyta atvejams, kai vartotojas tiksliai nežino kiek namų darbų įverčių įrašys
2) Pakeistos f-jos, kad tiktų naudoti su vektorių tipo kintamaisiais
# V0.1.4
1) Įtraukta galimybė, jog kompiuteris generuotų pažymius pats, o ne tik pasiimtų iš vartotojo
2) Pridėti ribojimai įvedamiems duomenims
# V0.2
1) Pridėta galimybė nuskaityti duomenis iš failo
2) Patobulintas skaičių generavimas
# V0.3
1) Naudojamos f-jos ir struktūros sukeltos į atskirus .cpp/.h failus
2) Kur reikia, naudojamas try-catch išimčių valdymui
# V0.4
1) Vartotojui suteikta galimybė pasirinkti, kad programa sugeneruotų vieno iš pasirinktų didumų failą
2) Įtraukta laiko skaičiavimo klasė, pateikianti atskirų veiksmų vykdymo trukmę
# V0.5
Ištirtas programos greitis priklausomai nuo naudojamo konteinerio (vector arba list). Gauti rezultatai:

|                   | List    | Vector  |
| -------------     |:------: | -----:  |
| `1000`            |         |         |
| Failo nuskaitymas | 0,0035s.|	0,029s. |
| Skirstymas        | 0,005s.	|	0,005s. |
| Iš viso           | 0,009s. | 0,035s. |
|`10000`            |         |         |
| Failo nuskaitymas | 0,032s.	|	0,032.  |
| Skirstymas        | 0,05s.	|	0,05s.  |
| Iš viso           | 0,08s.  | 0,08s.  |
| `100000`          |         |         |
| Failo nuskaitymas | 0.31s.	|	0,74s.  |
| Skirstymas        | 0.51s.	|	0,49s.  |
| Iš viso           | 0,82s.  | 1,23s.  |
| `1000000`         |         |         |
| Failo nuskaitymas | 3.1s.   |	3,01s.  |
| Skirstymas        | 4,96s.  |	4,93s.  |
| Iš viso           | 8,07s.  | 7,94s.  |
| `10000000`        |         |         |
| Failo nuskaitymas | 79,1s.  |	53,65s. |
| Skirstymas        | 628,2s. |	61,2s.  |
| Iš viso           | 707,3s. | 114,9s. |

PASTABOS
1) Namų darbų kiekis pastovus - 8
2) Visur skaičiuojamas vidurkinis galutinis balas


TESTAVIMO SISTEMOS CHARAKTERISTIKOS
1) CPU: 4 Core(s), 8 Logical Processor(s)
2) RAM: 8GB
3) HDD: 929GB

#V1.0
Abiems konteinerių tipams išmėginti kitokie studentų skirstymo metodai. Gauti tokie rezultatai (namuų darbų kiekis ir galutinis balas - kaip V0.5 versijoje):
|                         | List    | Vector  |
| -------------           |:------: | -----:  |
| `1000`                  |         |         |
| Skirstymas              | 0,007s.	|	0,007s. |
| Skirstymas kopijuojant  | 0,007s. | 0,007s. |
| Skirstymas trinant      | 0,008s. | 0,007s. |
| `10000`                 |         |         |
| Skirstymas              | 0,05s.	|	0,056s. |
| Skirstymas kopijuojant  | 0,057s. | 0,055s. |
| Skirstymas trinant      | 0,061s. | 0,058s. |
| `100000`                |         |         |
| Skirstymas              | 0,501s.	|	0,494s. |
| Skirstymas kopijuojant  | 0,77s.  | 0,522s. |
| Skirstymas trinant      | 0,556s. | 0,576s. |
| `1000000`               |         |         |
| Skirstymas              | 5,067s.	|	4,969s. |
| Skirstymas kopijuojant  | 5,901s. | 5,594s. |
| Skirstymas trinant      | 5,73s.  | 6,142s. |
| `10000000`              |         |         |
| Skirstymas              | 54,51s. |	56,05s. |
| Skirstymas kopijuojant  | 211,36s.| 199,296s.|
| Skirstymas trinant      | 68,303s.| 137,74s.|

