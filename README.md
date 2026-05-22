# Nguyễn Đình Vũ's Portfolio

## Professional Statement

My name is Vu. I possess strong problem-solving and analytical skills, complemented by effective communication abilities. I am dedicated to identifying and analyzing potential risks, threats, and vulnerabilities to ensure the confidentiality, integrity, and availability of assets. My commitment is to help safeguard organizations and individuals by enhancing their security posture. I deeply value the critical role that security plays in protecting both organizations and people.

## 🚀 Projects Portfolio

This repository serves as a centralized hub for my engineering, development, and cybersecurity projects.

---

### 🛠️ Project Showcases

The table below aggregates the active submodules included in this portfolio. You can click on the links under **Project Repository** to navigate directly to the corresponding source code on GitHub.

| Project Category | Project Name | Tech Stack | Key Implementation Focus | Project Repository |
| :--- | :--- | :--- | :--- | :--- |
| **🕹️ Games** | SAIKYOU-SAMURAI-PROJECT | Java | Object-oriented design, game loop control, and 2D character state management. | [View Repository](https://github.com/huntervu1337/SAIKYOU-SAMURAI-PROJECT) |
| **🕹️ Games** | Hex-Game | Java | Hexagonal grid computing, strategic game mechanics, and graphical interface rendering. | [View Repository](https://github.com/huntervu1337/Hex-Game) |
| **💻 Linux** | My-Shell | C | Unix system programming, process management (fork/exec), and system command execution. | [View Repository](https://github.com/huntervu1337/My-Shell) |
| **🛰️ Research Project** | GNSS-SDR | Python | Satellite navigation signal processing and software-defined receiver architectures. | [View Repository](https://github.com/huntervu1337/GNSS-SDR) |
| **🌐 Backend Web App** | BluemoonManagement | Java / Spring Boot | Residential administration platform, role-based access control (RBAC), and secure REST APIs. | [View Repository](https://github.com/khoatran18/BluemoonManagement) |
| **🌐 Backend Web App** | OnlineQuiz | Java / Spring Boot | Real-time online quiz application leveraging WebSockets for low-latency live synchronization. | [View Repository (Branch: be2-game-websocket)](https://github.com/tungvuhoang/BTL_CNWeb/tree/be2-game-websocket) |
| **🤖 AI-ML** | Route-finding-on-map | Python | Advanced search algorithms and AI techniques for optimized pathfinding on digital maps. | [View Repository](https://github.com/huntervu1337/Project-AI) |
| **🤖 AI-ML** | SSH-anomaly-detection-using-ML | Python | Machine learning-driven log analysis to detect unauthorized access patterns and SSH anomalies. | [View Repository](https://github.com/huntervu1337/SSH-anomaly-detection-using-ML) |

---

## 🔒 Cybersecurity Lab Exercises & Frameworks

In addition to software repositories, this portfolio includes structured engineering documentation covering end-to-end security analysis, located within the local `/Cybersecurity` directories:

### 1. Security Operations (SIEM & Threat Intelligence)
* **Incident Response & Threat Detection:** Practiced structural alerting, monitoring, and triaging within Security Operations Center (SOC) environments.
* **SIEM Operations (Splunk & Chronicle):** Executed advanced search queries to investigate authentication logs, filter out failed root SSH login attempts over mail servers, map user asset timelines, and track malicious HTTP POST interactions.
* **Threat Intelligence Integration:** Integrated contextual intelligence utilizing external sources including **VirusTotal** for evaluating Indicators of Compromise (IoCs), checking multi-domain infrastructure mapping via malicious IP resolutions, and mapping adversary tactics to the **MITRE ATT&CK** framework.

### 2. Security Auditing & Threat Modeling
* **Safety & Compliance Auditing:** Developed compliance gap analysis reports and control checklists based on NIST CSF, PCI-DSS, and GDPR guidelines using the `Botium Toys` business case.
* **PASTA Threat Modeling:** Applied the Process for Attack Simulation and Threat Analysis (PASTA) framework to map threat vectors, analyze application architectures via data flow diagrams, and establish mitigation strategies.

### 3. Network Analysis & Incident Documentation
* **Packet Capture & Analysis:** Utilized `Wireshark` and `tcpdump` to dissect network layer communications, analyze protocol structures (UDP/ICMP/TCP), and isolate active malicious traffic streams such as ICMP flooding and SYN floods.
* **Incident Handling Notebooks:** Compiled step-by-step incident response logs mapping out the 5 Ws (Who, What, Where, When, Why) to investigate, contain, and recover infected enterprise hosts from phishing and ransomware deployment scenarios.
* **OS Hardening & Mitigation:** Documented host-level hardening mechanisms, multi-factor authentication (MFA) rollouts, and specific playbooks for mitigating ongoing brute-force web-panel attacks.

### 4. Linux Permissions, Databases & Automation
* **Authorization Management:** Implemented file-system access control policies using Linux command-line structures (`chmod`, `ls -la`) to enforce strict user-group permissions and least-privilege principles.
* **Data Filtration via SQL:** Structured specialized database queries utilizing conditional expressions (`WHERE`, `AND`, `OR`, `NOT`) and wildcards to scan system tables and audit suspicious login dates or geographical patterns.
* **Security Script Automation:** Engineered a Python-based automation algorithm to dynamically parse, extract, split, and rewrite text-based data lists to strip unauthorized IP blocks out of access files (`allow_list.txt`).
