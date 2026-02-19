<h1>ESP32 IoT Heat Risk & Climate Adaptive Safety System</h1>

<h2>Description</h2>
This project consists of an <b>ESP32-S2 based IoT heat monitoring and automated safety system</b> designed for real-time environmental monitoring in healthcare, laboratory, or server room environments.  

The system integrates a <b>DHT22 temperature & humidity sensor, OLED display, relay control, and MQTT cloud communication</b> to monitor environmental conditions and trigger automated safety actions.  

When the temperature exceeds a defined threshold, the system activates a <b>relay (e.g., fan), visual LED warning, and cloud alert</b> while displaying status updates locally on an OLED screen.  

The device connects securely to the cloud (ThingsBoard) using the <b>MQTT protocol</b> and supports scalable multi-device monitoring.  

Developed as part of an Embedded Systems & IoT course project, this system demonstrates practical implementation of real-time systems, networking protocols, hardware-software integration, and resilient edge computing design.

<br />
<h2>Presentation</h2>

📊 <b>View the presentation here:</b>  
🔗 <a href="https://github.com/marriammahmed/IoT_HRCAS/blob/main/HRCAS%20(1).pptx">Download Presentation (HRCAS)</a>

<br />
<br />

<b>Course Outcomes & Skills:</b>  
This course focused on embedded systems, real-time processing, IoT communication, and system-level architecture. Key technical skills and knowledge gained include:  

- Mastery of <b>microcontroller architecture (ESP32-S2)</b> and GPIO hardware configuration  
- Understanding of <b>real-time sensor communication</b> (single-wire DHT protocol timing constraints)  
- Implementation of <b>MQTT publish/subscribe networking model</b> for IoT cloud communication  
- Practical use of <b>I2C communication protocol</b> for OLED display integration  
- Embedded C++ object-oriented programming using global object construction and class-based architecture  
- Design of <b>edge-first safety systems</b> where critical actions occur locally even during network failure  
- Implementation of threshold-based control logic with fail-safe architecture  
- Cloud telemetry integration with ThingsBoard dashboard  
- Debugging of USB CDC communication and embedded system boot sequence  

The project demonstrates a full-stack IoT workflow:
Sensor → Microcontroller → Local Decision Logic → Cloud Platform → Visualization Dashboard


<br />

<h2>Languages and Utilities Used</h2>

- <b>C++ (Arduino Framework)</b>  
- <b>ESP32 Arduino Core</b>  
- <b>MQTT Protocol (PubSubClient)</b>  
- <b>ThingsBoard Cloud Platform</b>  
- <b>I2C Communication (Wire Library)</b>  
- <b>Adafruit GFX & SSD1306 OLED Driver</b>  

<br />

<h2>Hardware Components</h2>

- <b>ESP32-S2 Microcontroller</b>  
- <b>DHT22 Temperature & Humidity Sensor</b>  
- <b>0.96" OLED Display (SSD1306, I2C)</b>  
- <b>Relay Module (Fan / Cooling Control)</b>  
- <b>Status LED</b>  
- Breadboard & External Power Supply  

<br />

<h2>Environments Used</h2>

- <b>Arduino IDE</b>  
- <b>ThingsBoard Cloud</b>  
- <b>ESP32-S2 Dev Module</b>  
- <b>macOS / Windows Serial Monitor</b>  

<br />

<h2>System Architecture</h2>

<b>Edge-Based Safety Model:</b>

- Sensor data is read locally every 30 seconds  
- Threshold logic determines danger state  
- LED and relay activate immediately on critical temperature  
- Telemetry data is published via MQTT  
- Cloud dashboard visualizes environmental conditions  

This architecture ensures local safety even if internet connectivity fails.

<br />

<h2>Program Walk-through</h2>

<p align="center">
WOKWI Simulation of System Architecture: <br/>
<img src="https://i.imgur.com/gISCcM8.png" height="80%" width="80%" alt="Serial Monitor Boot"/>
<br />
<br />
UI: <br/>
<img src="https://i.imgur.com/jRcxbIH.png" height="80%" width="80%" alt="OLED Display"/>
<br />
<br />
Hardware setup: <br/>
<img src="https://i.imgur.com/TUOeL6J.jpeg" height="80%" width="80%" alt="ThingsBoard Dashboard"/>
<br />
<br />
Adafruit.io integration: <br/>
<img src="https://i.imgur.com/v2CWw9l.png" height="80%" width="80%" alt="ThingsBoard Dashboard"/>
<br />
<br />
</p>

<br />

<h2>Project Workflow</h2>

1. ESP32 initializes WiFi and connects to MQTT broker  
2. DHT22 reads temperature & humidity  
3. System evaluates temperature against defined threshold  
4. If temperature ≥ 35°C:
   - LED turns ON  
   - Relay activates (fan ON)  
   - OLED displays "STATUS: DANGER"  
5. Sensor data is formatted into JSON payload  
6. MQTT publishes telemetry to ThingsBoard  
7. Cloud dashboard updates in real-time  

<br />

<h2>Future Improvements & Startup Vision</h2>

To evolve this project into a scalable IoT startup solution, planned enhancements include:

- MQTT over TLS (encrypted communication)  
- OTA (Over-The-Air) firmware updates  
- Multi-device fleet management  
- Predictive anomaly detection (AI integration)  
- SMS/Email emergency notifications  
- Flash memory logging during network outages  
- Custom PCB & enclosure for deployment  
- Mobile companion dashboard  

Potential application domains:
- Hospital patient room monitoring  
- Vaccine cold-chain monitoring  
- Laboratory environmental control  
- Server room heat protection  
- Smart building automation  

<br />

<h2>Key Learning Outcomes</h2>

This project demonstrates:

- Embedded systems programming  
- Real-time hardware interaction  
- IoT networking fundamentals  
- Cloud-based telemetry systems  
- Fault-tolerant system design  
- Integration of hardware and distributed cloud infrastructure  

<br />

<h2>Conclusion</h2>

This project represents a complete end-to-end IoT system combining hardware, firmware, networking, and cloud integration.  

It showcases how embedded systems can provide intelligent, reliable, and scalable safety monitoring solutions suitable for real-world deployment and future commercialization.
