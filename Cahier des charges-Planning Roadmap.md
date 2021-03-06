Cahier des charges : Athlete rover prototype


	Dans le cadre des futures missions spatiales et notamment celle du retour de l’Homme sur la Lune, la NASA développe actuellement le rover Athlete (All-Terrain Hex-Limbed Extra-Terrestrial Explorer ). Un robot de transport capable de se déplacer sur une multitude de terrains différents grâce à un système d’articulé des roues.

	Dans le cadre de la formation de Peip2, je souhaite travailler sur un robot capable de réaliser la montée et la descente d’un obstacle afin de simuler le comportement d’Athlete lors de son déplacement sur des reliefs escarpés. Le robot doit être manipulé à distance avec un système de télécommande capable de gérer les différentes paires de roues, ainsi que le déplacement du robot.
	Le projet pourra être étendu en prenant en compte la stabilité du socle destiné à transporter du matériel. L’automatisation du robot pourrait être envisagée (autre projet).

Objectif : robot capable de monter et descendre un obstacle de surface plate (type : marche d’escalier). 

Lors des phases de montée : le train avant se soulève, le robot s’avance, les roues avants prennent contact sur l’obstacle. Ensuite les roues centrales se soulèvent, le robot s’avance, le roues centrales prennent contact avec l’obstacle. Enfin le train arrière se relève. Le poids est ainsi porté par l’avant du robot qui s’avance jusqu’à ce que le train arrière prenne contact avec le sol. Le robot reprend ensuite sa hauteur par défaut

Lors des phases de descente : Le robot s’avance jusqu’à avoir le train avant dans le vide. Il s’abaisse jusqu’à se que les roues avants prennent contact avec le sol. Ensuite même démarche pour le train central et le train arrière.

Contraintes de réalisation :

Contraintes internes au robot :

- le robot doit être équipé de 3 paires de roues au minimum pour la gestion du centre de gravité.
- les trains avants et arrières doivent posséder des roues motrices et des pneus adhérents au sol afin de pouvoir pousser ou tracter le robot lors des phases de montée et de descente.
- le robot doit pouvoir communiquer à distance avec une télécommande. Un système de transfert de données est donc nécessaire (Bluetooth, …)
- chaque train doit être capable de fonctionner indépendamment des autres. Mais aussi tous ensemble. 
- Le poids et les matériaux utilisés doivent être pris en compte afin de permettre une meilleure gestion du centre de gravité.
- chaque train de roues doit être capable de s’abaisser et se relever. Son articulation nécessite une motorisation
- le train avant doit être capable d’orienter ses roues avants pour guider le robot.
- la programmation de la carte doit permettre de tester indépendamment chaque mouvement du robot. Ainsi que le mouvement global
- Le robot nécessite d’avoir avec lui une source d’énergie : pile,etc
- nécessité de modéliser les articulations des différents trains mobiles.
- nécessité d’une quantité importante de moteurs et roues

Contraintes externes

- délais : 8 semaines
- ouverture du FabLab
- budget

Tâches à effectuer :

1 Création /Programmation d’un train articulé
2  Création /Programmation des roues d’un train
3 Communication télécommande et carte
4 Multiplication des trains articulé
5 Création du socle et gestion de l’énergie
6 Assemblage final
7 (Système éclairage)
8 (Système d’alarme de stabilité)




Problèmes possibles :

- programmation du mouvement des trains de roues
- construction des articulations
- gestion du poids et centre de gravité (= stabilité)
- communication télécommande / carte Arduino



Évolutions potentielles :

- système d’alarme lorsque la plateforme dépasse un certain angle
- système de capteur ( de contact, ou d’ultrasons) pour détecter la distance de l’obstacle
- système d’éclairage
