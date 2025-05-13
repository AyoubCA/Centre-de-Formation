




[![Contributors][contributors-shield]][contributors-url][![Forks][forks-shield]][forks-url][![Stargazers][stars-shield]][stars-url][![Issues][issues-shield]][issues-url][![MIT License][license-shield]][license-url][![LinkedIn][linkedin-shield]][linkedin-url]



  
    
  

  Système de Gestion de Centre de Formation

  
    A C++ console application for managing a training center's trainers and their details!
    
    Explore the docs »
    
    
    View Demo
    ·
    Report Bug
    ·
    Request Feature
  




  Table of Contents
  
    
      About The Project
      
        Built With
      
    
    
      Getting Started
      
        Prerequisites
        Installation
      
    
    Usage
    Roadmap
    Contributing
    Contact
    Acknowledgments
  



About The Project



This C++ console application is designed to manage a training center, handling three types of trainers: Formateur (general), FormateurSpec (specialized), and FormateurOnline (online), along with a CentreFormation. It provides a text-based menu interface to add, modify, delete, and query trainer data, including languages, specialties, and availability.
Here's why this project is useful:

Streamlines trainer management with a simple, interactive console interface.
Supports advanced queries like finding trainers with specific language proficiency or specialties.
Implements object-oriented principles for maintainable and scalable code.

This application is ideal for educational or administrative use in training centers looking for a lightweight management solution.
(back to top)

Built With

[![C++][C++]][C++-url]

(back to top)


Getting Started
Follow these steps to set up and run the project locally.
Prerequisites

C++ Compiler: g++, clang++, or any compiler supporting C++11 or higher.# Example: Install g++ on Ubuntu
sudo apt-get install g++


Git: For cloning the repository.# Install Git on Ubuntu
sudo apt-get install git



Installation

Clone the repogit clone https://github.com/your_username/repo_name.git


Navigate to the project directorycd repo_name


Compile the projectg++ -std=c++11 *.cpp -o gestion_centre_formation


Run the application./gestion_centre_formation



(back to top)


Usage
Launch the application to access a text-based menu. Navigate using numeric inputs to:

Add, modify, or delete trainers (name, first name, CIN).
Manage languages and proficiency levels for general trainers.
Add or remove specialties for specialized trainers.
Set availability days for online trainers.
Perform advanced queries, such as listing trainers with C1 proficiency in multiple languages or by specialty.

Example Menu:
=== Menu Principal ===
1. Ajouter un formateur
2. Afficher les formateurs
3. Rechercher par langue
4. Quitter
Entrez votre choix : 

For detailed usage, refer to the Documentation (update with actual link if available).
(back to top)


Roadmap

 Implement core trainer management features
 Add support for advanced queries
 Add file-based data persistence
 Implement a graphical user interface (GUI)
 Support multiple languages for the interface
 French
 English



See the open issues for a full list of proposed features and known issues.
(back to top)


Contributing
Contributions are welcome to enhance this project! To contribute:

Fork the Project
Create your Feature Branch (git checkout -b feature/AmazingFeature)
Commit your Changes (git commit -m 'Add some AmazingFeature')
Push to the Branch (git push origin feature/AmazingFeature)
Open a Pull Request

(back to top)


License
Distributed under the MIT License. See LICENSE.txt for more information.
(back to top)


Contact
Your Name - @your_twitter - email@example.com
Project Link: https://github.com/your_username/repo_name
(back to top)


Acknowledgments

Choose an Open Source License
GitHub Emoji Cheat Sheet
Img Shields

(back to top)


[contributors-shield]: https://img.shields.io/github/contributors/your_username/repo_name.svg?style=for-the Badge
