<details>
  <summary>
    Tema 1
  </summary>
  
### Cerință:
> Simularea unei stații de încărcare vehicule electrice, folosind mai multe LED-uri și butoane.

### Detalii tehnice: 
> (1p) LED-ul RGB reprezintă disponibilitatea stației. Dacă stația este liberă, LED-ul va fi verde, iar dacă stația este ocupată, se va face roșu.

> (2p) LED-urile simple reprezintă gradul de încărcare al bateriei, pe care îl vom simula printr-un loader progresiv (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%). Loader-ul se încarcă prin aprinderea succesivă a LED-urilor, la un interval fix de 3s. LED-ul care semnifică procentul curent de încărcare va avea starea de clipire, LED-urile din urma lui fiind aprinse continuu, iar celelalte stinse.

> (1p) Apăsarea scurtă a butonului de start va porni încărcarea. Apăsarea acestui buton în timpul încărcării nu va face nimic.

> (2p) Apăsarea lungă a butonului de stop va opri încărcarea forțat și va reseta stația la starea liberă. Apăsarea acestui buton cât timp stația este liberă nu va face nimic.

### Pentru acest proiect am folosit:
> 4x LED-uri (pentru a simula procentul de încărcare)

> 1x LED RGB (pentru starea de liber sau ocupat)

> 2x Butoane (pentru start încărcare și stop încărcare)

> 8x Rezistoare (7x 220/330ohm, 2x 1K)

> Breadboard

> Linii de legătură

### Cum funcționează?
> La început, "stația" este liberă, ceea ce înseamnă că LED-ul RGB este verde, iar LED-urile de încărcare sunt stinse.

> Butonul START pornește încărcarea, adică LED-ul RGB se face roșu, după care LED-ul L1 clipeste timp de 3 secunde, iar la final rămâne aprins, urmând ca cel de-al doilea să facă același lucru, și așa mai departe.

> Când toate cele 4 LED-uri au trecut prin această stare, ele vor clipi simultan de 3 ori, iar apoi se vor stinge, iar LED-ul RGB va deveni din nou verde.

> Dacă în orice moment pe parcursul încărcării se apasă minim o secundă butonul de STOP, încărcarea se va opri.

> Când butoanele de START / STOP sunt apăsate scurt în timpul încărcării, nu se va întâmpla nimic.

### Poze cu implementarea pe breadboard:
<p>
  <img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_1/media/1.jpg?raw=true" width="300"/>
  <img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_1/media/2.jpg?raw=true" width="300"/>
  <img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_1/media/3.jpg?raw=true" width="300"/>
</p>

### Schema electrică
<img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_1/media/sch.jpg?raw=true" width="300"/>

### Video:
<a href="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_1/media/vid.mp4?raw=true" download="Tema1_Video.mp4">Descarcă video Tema 1</a>
</details>


<details>
  <summary>
    Tema 2
  </summary>
  
### Cerință:
> Crearea unui joc asemănător cu TypeRacer

### Detalii tehnice: 
> **LED RGB - Indicator de stare:**
> În starea de repaus, LED-ul va avea culoarea albă.
> La apăsarea butonului de start, LED-ul va clipi timp de 3 secunde, indicând o numărătoare inversă până la începerea rundei.
> În timpul unei runde: LED-ul va fi verde dacă textul introdus este corect și va deveni roșu în caz de greșeală.

> **Butonul Start/Stop:**
> Modul de repaus: Dacă jocul este oprit, apăsarea butonului inițiază o nouă rundă după o numărătoare inversă de 3 secunde.
> În timpul unei runde: Dacă runda este activă, apăsarea butonului o va opri imediat.

> **Butonul de dificultate:**
> Butonul de dificultate controlează viteza cu care apar cuvintele și poate fi folosit doar în starea de repaus.
> La fiecare apăsare, dificultatea se schimbă ciclind între: (Easy, Medium, Hard).
> La schimbarea dificultății, se trimite un mesaj prin serial: “Easy/Medium/Hard mode on!”.
> Pentru gestionarea apăsărilor butoanelor, se utilizează debouncing și întreruperi. Timerele sunt folosite pentru a seta frecvența apariției cuvintelor.

> **Generarea cuvintelor:**
> Se va crea un dicționar de cuvinte.
> În timpul unei runde, cuvintele vor fi afișate în terminal într-o ordine aleatorie.
> Dacă cuvântul curent a fost scris corect, un cuvânt nou va fi afișat imediat. Dacă nu, un nou cuvânt va apărea după intervalul de timp stabilit în funcție de dificultate.
> Pentru a genera numere aleatorii, se utilizează funcția `random()`.

> **Alte observații:**
> Timpul alocat pentru o rundă este de 30 de secunde.
> La sfârșitul fiecărei runde, se va afișa în terminal câte cuvinte au fost scrise corect.

### Pentru acest proiect am folosit:
> Arduino UNO (ATmega328P microcontroller)
> 
> 1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
> 
> 2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
> 
> 5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
> 
> Breadbord
> 
> Fire de legătură

### Cum funcționează?
> Jocul este în repaus. LED-ul RGB are culoarea albă.

> Se alege dificultatea jocului folosind butonul de dificultate, iar în terminal va apărea “Easy/Medium/Hard mode on!”.

> Se apasă butonul de start/stop.

> LED-ul clipește timp de 3 secunde, iar în terminal se va afișa numărătoarea înversă: 3, 2, 1.

> LED-ul devine verde și încep să apară cuvinte de tastat.

> La tastarea corectă, următorul cuvânt apare imediat. Dacă nu se tastează cuvântul în timpul stabilit de dificultate, va apărea un nou cuvânt.

> O greșeală face LED-ul să devină roșu. Pentru a corecta cuvântul, se va folosi tasta BackSpace.

> După 30 de secunde, runda se termină, iar în terminal se va afișa scorul: numărul total de cuvinte scrise corect.

> Jocul se poate opri oricând cu butonul de start/stop.

### Poze cu implementarea pe breadboard:
<p>
  <img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_2/media/1.JPG?raw=true" width="300"/>
  <img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_2/media/2.JPG?raw=true" width="300"/>
</p>

### Schema electrică
<img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_2/media/wokwi.jpg?raw=true" width="300"/>

### Video:
<a href="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_2/media/vid.MOV?raw=true" download="Tema2_Video.MOV">Descarcă video Tema 2</a>

</details>

<details>
  <summary> Tema 3</summary>

## Descriere
Această temă reprezintă un joc competitiv de reflex pentru doi jucători. Scopul fiecărui jucător este să apese cât mai rapid butonul asociat culorii afișate pe LED-ul RGB. Punctajul este afișat pe un LCD și actualizat pe parcursul jocului. La final, jocul indică câștigătorul și scorul final.

## Componente utilizate
- **6x LED-uri** (2 grupuri de câte 3 LED-uri, fiecare grup având culori diferite)
- **2x LED RGB** (1 pentru fiecare jucător)
- **6x butoane** (3 pentru fiecare jucător)
- **1x LCD**
- **1x servomotor**
- **2x Breadboard**
- **Fire de legătură**
- **2x Arduino Uno**

## Cerințe
1. **Inițializare**
   - La pornirea jocului, un mesaj de bun venit este afișat pe LCD.
   - Jocul poate fi pornit printr-un buton dedicat sau apăsarea unui buton dintre cele existente.

2. **Desfășurarea Rundelor**
   - Fiecare jucător are 3 butoane și un LED RGB. LED-ul RGB afișează o culoare, iar jucătorul trebuie să apese rapid butonul corespunzător.
   - Răspunsul corect aduce puncte, iar răspunsul mai rapid oferă punctaj mai mare.
   - La finalul fiecărei runde, punctajul este actualizat pe LCD.

3. **Finalizarea Jocului**
   - Servomotorul indică progresul jocului. O rotație completă marchează sfârșitul jocului.
   - LCD-ul afișează câștigătorul și scorul final, apoi revine la ecranul de start.
  
## Bonusuri implementate
- **Animație pe LCD** la pornirea jocului.
- **Numele jucătorilor** introduse prin interfața serială.

## Poze cu implementarea pe breadboard
<p>
  <img src="https://github.com/mariaxadina/Robotica/blob/main/Tema_3/media/1.JPG?raw=true" width="300"/>
  <img src="https://github.com/mariaxadina/Robotica/blob/main/Tema_3/media/2.JPG?raw=true" width="300"/>
  <img src="https://github.com/mariaxadina/Robotica/blob/main/Tema_3/media/3.JPG?raw=true" width="300"/>
  <img src="https://github.com/mariaxadina/Robotica/blob/main/Tema_3/media/4.JPG?raw=true" width="300"/>
  <img src="https://github.com/mariaxadina/Robotica/blob/main/Tema_3/media/5.JPG?raw=true" width="300"/>
</p>

## Schema electrică
<img src="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_3/media/video.MP4?raw=true" width="300"/>

## Video
<a href="https://github.com/gabirelul/IR_CTI_3/blob/main/Tema_3/media/video.MP4?raw=true" download="Tema2_Video.MOV">Descarcă video Tema 3</a>

## Publicare
Codul proiectului se găsește pe GitHub și include toate detaliile necesare pentru replicarea proiectului.

</details>
