## Introducere în Robotică
# Tema 1
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
[Vizualizează video](https://github.com/gabirelul/IR_CTI3/blob/main/Tema_1_robo/media/vid.mp4?raw=true)
// [Vizualizează pe YouTube]()
