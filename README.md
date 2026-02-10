#########################################################
#                                                       #
#        TAKTİKİ ŞİFRƏLƏMƏ VƏ RABİTƏ TERMİNALI          #
#            BUILD VERSION: 2026.1.0-STABLE             #
#                                                       #
#########################################################

## 🛡️ Layihə Haqqında
Bu layihə, strateji əhəmiyyətli əmrlərin mərkəzi terminaldan (C# WinForms) uzaqdakı cihazlara (ESP32) təhlükəsiz və şifrəli şəkildə ötürülməsini simulyasiya edən bir **IoT Müdafiə Sistemi** prototipidir.
Məlumatlar yolda XOR şifrələmə ilə qorunur və MQTT protokolu vasitəsilə dünya səviyyəsində ötürülə bilir.

Sistem, kiber-müdaxilələrin qarşısını almaq üçün məlumatları simmetrik şifrələmə alqoritmi ilə qoruyur və real vaxt rejimində MQTT protokolu üzərindən rabitə qurur.

## 🔗 Canlı Simulyasiya
Layihənin aparat (hardware) hissəsini heç bir cihaz almadan birbaşa brauzerinizdə test edə bilərsiniz:
👉 **[Wokwi Simulyasiya Linki](https://wokwi.com/projects/455579231699074049)**

## 🚀 Sistemi Necə İşə Salmalı? (Addım-addım)

Sistemi test etmək üçün bu ardıcıllığı izləyin:

1. **Terminalı Açın:** `C#(WIndows-Form)_Taktiki Şifrələmə və Rabitə Terminalı` qovluğundakı `.slnx` faylını **Visual Studio** proqramında açın və "Start" düyməsini basaraq işə salın.
2. **Simulyasiyaya Daxil Olun:** Aşağıdakı Wokwi linkinə klikləyin:
   👉 [](https://wokwi.com/projects/455579231699074049)
3. **Simulyasiyanı Başladın:** Wokwi-də yuxarıdakı **"Play" (Yaşıl üçbucaq)** düyməsini sıxın. (Hesabınıza köçürməyə ehtiyac yoxdur, birbaşa işləyir).
4. **Əmr Göndərin:** C# proqramında mesaj hissəsinə bir əmr (məsələn: `ATTACK` və ya `STOP`) yazın və **"Göndər"** düyməsinə basın.

## 📈 Gözlənilən Nəticələr

Göndər düyməsini basdıqdan sonra cihazda (Wokwi) aşağıdakılar baş verəcək:

* **LCD Ekran:** İlk sətirdə mesajın şifrəli halını (**HEX formatında**), ikinci sətirdə isə deşifrə olunmuş (oxunaqlı) halını görəcəksiniz.
* **RGB LED:** * Əgər `ATTACK` göndərsəniz -> **YAŞIL** işıq yanacaq.
    * Əgər `STOP` göndərsəniz -> **QIRMIZI** işıq yanacaq.
    * Digər mesajlarda -> **SARI** (Gözləmə) işığı yanacaq

## 🚀 Əsas Funksiyalar
- **XOR Cryptography:** Mesajlar ötürülməzdən əvvəl xüsusi açarla şifrələnir və yalnız ESP32 tərəfində deşifrə olunur.
- **MQTT Connectivity:** Dünyanın istənilən yerindən aşağı gecikmə ilə idarəetmə imkanı.
- **Visual Feedback:** 16x2 I2C LCD ekranında şifrəli (HEX) və deşifrə edilmiş (Plain Text) mesajların nümayişi.
- **RGB Status Indication:** Gələn əmrin növünə görə (ATTACK, STOP) LED indikatorunun rəng dəyişməsi.
- **Case Sensitivity Fix:** İstifadəçi daxil etdiyi əmrin böyük/kiçik hərflə olmasından asılı olmayaraq ağıllı emal sistemi.


## 🛠️ İstifadə Olunan Texnologiyalar və Komponentlər

### Proqram Təminatı (Software)
* **C# .NET Framework:** İdarəetmə interfeysi (GUI) üçün.
* **C++ (Arduino):** ESP32-nin daxili məntiqi üçün.
* **HiveMQ MQTT Broker:** Məlumatların internet üzərindən terminaldan cihaza ötürülməsini təmin edən "bulud" mərkəzi.
* **XOR Alqoritmi:** Mesajların kiber-müdaxilədən qorunması üçün istifadə edilən sürətli şifrələmə metodu.
* - **Wokwi:** Simulyator
* - **Kitabxanalar:** `M2Mqtt`, `LiquidCrystal_I2C`, `PubSubClient`

### Avadanlıq/Sensorlar (Hardware)
* **ESP32 Microcontroller:** Sistemin beyni, WiFi dəstəkli idarəetmə çipi.
* **16x2 I2C LCD:** Məlumatları vizuallaşdırmaq üçün ekran.
* **RGB LED:** Əmrlərin statusunu vizual olaraq göstərən rəngli indikator.
* **Virtual Gateway:** WiFi modulu vasitəsilə internet bağlantısı.


