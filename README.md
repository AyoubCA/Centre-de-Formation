
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h3 align="center">Training Center Management System</h3>
  <p align="center">
    A C++ console application for managing trainers, specialties, and availability in a training center.
    <br />
    <a href="https://github.com/AyoubCA/gestion-centre-formation"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/AyoubCA/gestion-centre-formation/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/AyoubCA/gestion-centre-formation/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#built-with">Built With</a></li>
    <li><a href="#getting-started">Getting Started</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#project-structure">Project Structure</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This C++ console application provides a comprehensive system to manage a training center, including:

### Key Features
- **Trainer Management**:
  - Create/update trainers (Formateur) with languages and proficiency levels
  - Handle specialized trainers (FormateurSpec) with domains of expertise
  - Manage online trainers (FormateurOnline) with availability days

- **Advanced Operations**:
  - Add/remove languages (e.g., French C1, English B2)
  - Add/remove specialties (e.g., Programming, Design)
  - Check online trainer availability
  - Complex queries:
    - Find trainers with C1 proficiency in two languages
    - Search by specialty or language level
    - Identify trainers with multiple specialties

- **Data Integrity**:
  - Unique CIN validation
  - Exception handling for duplicate entries
  - Language comparison utilities


### Built With
-C++
<!-- GETTING STARTED -->
## Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- C++11 or newer standard support

### Installation
1. Clone the repo:
   ```sh
   git clone https://github.com/AyoubCA/gestion-centre-formation.git
