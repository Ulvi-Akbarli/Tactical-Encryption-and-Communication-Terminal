#########################################################
#                                                       #
#        TAKTİKİ ŞİFRƏLƏMƏ VƏ RABİTƏ TERMİNALI          #
#            BUILD VERSION: 2026.1.0-STABLE             #
#                                                       #
#########################################################

## 🛡️ Layihə Haqqında
Bu layihə, strateji əhəmiyyətli əmrlərin mərkəzi terminaldan (C# WinForms) uzaqdakı cihazlara (ESP32) təhlükəsiz və şifrəli şəkildə ötürülməsini simulyasiya edən bir **IoT Müdafiə Sistemi** prototipidir.

Sistem, kiber-müdaxilələrin qarşısını almaq üçün məlumatları simmetrik şifrələmə alqoritmi ilə qoruyur və real vaxt rejimində MQTT protokolu üzərindən rabitə qurur.

## 🔗 Canlı Simulyasiya
Layihənin aparat (hardware) hissəsini heç bir cihaz almadan birbaşa brauzerinizdə test edə bilərsiniz:
👉 **[Wokwi Simulyasiya Linki](https://wokwi.com/projects/455579231699074049)**

## 🚀 Əsas Funksiyalar
- **XOR Cryptography:** Mesajlar ötürülməzdən əvvəl xüsusi açarla şifrələnir və yalnız ESP32 tərəfində deşifrə olunur.
- **MQTT Connectivity:** Dünyanın istənilən yerindən aşağı gecikmə ilə idarəetmə imkanı.
- **Visual Feedback:** 16x2 I2C LCD ekranında şifrəli (HEX) və deşifrə edilmiş (Plain Text) mesajların nümayişi.
- **RGB Status Indication:** Gələn əmrin növünə görə (ATTACK, STOP) LED indikatorunun rəng dəyişməsi.
- **Case Sensitivity Fix:** İstifadəçi daxil etdiyi əmrin böyük/kiçik hərflə olmasından asılı olmayaraq ağıllı emal sistemi.

## 🛠️ Texniki Stack
- **Terminal:** C# .NET Framework (WinForms)
- **Firmware:** C++ / Arduino (ESP32)
- **Protokol:** MQTT (HiveMQ Broker)
- **Simulyator:** Wokwi
- **Kitabxanalar:** `M2Mqtt`, `LiquidCrystal_I2C`, `PubSubClient`



