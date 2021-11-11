# V0.5
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
| Failo nuskaitymas | 0,034s.	|	0,023s. |
| Skirstymas        | 0,008s.	|	0,008s. |
| `10000`           |         |         |
| Failo nuskaitymas | 0,853s.	|	0,474s. |
| Skirstymas        | 0,217s.	|	0,214s. |
| `100000`          |         |         |
| Failo nuskaitymas | 8.516s.	|	4.868s. |
| Skirstymas        | 2.142s.	|	2.096s. |
| `1000000`         |         |         |
| Failo nuskaitymas | 87.955s.|	51.563s.|
| Skirstymas        | 21.46s. |	21.315s. |

PASTABOS
1) Namų darbų kiekis pastovus - 8
2) Visur skaičiuojamas vidurkinis galutinis balas


TESTAVIMO SISTEMOS CHARAKTERISTIKOS
1) CPU: 4 Core(s), 8 Logical Processor(s)
2) RAM: 8GB
3) HDD: 929GB
