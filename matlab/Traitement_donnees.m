%% Nettoyage de l'environnement Matlab

clc
close all
clear all

%% Importation des donn?es

% Main totale

MainTotale1 = xlsread('MainTotale1.xlsx') ;
temps_main_1_1 = MainTotale1(:,1) ;
sig_main_1_1 = MainTotale1(:,2) ;
sig_main_1_2 = MainTotale1(:,3) ;
temps_main_1_2 = MainTotale1(:,4) ; 
sig_main_1_3 = MainTotale1(:,5) ;

MainTotale2 = xlsread('MainTotale2.xlsx') ;
temps_main_2_1 = MainTotale2(:,1) ;
sig_main_2_1 = MainTotale2(:,2) ; 
sig_main_2_2 = MainTotale2(:,3) ;
temps_main_2_2 = MainTotale2(:,4) ;
sig_main_2_3 = MainTotale2(:,5) ; 

MainTotale3 = xlsread('MainTotale3.xlsx') ;
temps_main_3_1 = MainTotale3(:,1) ;
sig_main_3_1 = MainTotale3(:,2) ;
sig_main_3_2 = MainTotale3(:,3) ;
temps_main_3_2 = MainTotale3(:,4) ;
sig_main_3_3 = MainTotale3(:,5) ;

% Annulaire

annulaire = xlsread('Annulaire.xlsx') ;
temps_annulaire_1_1 = annulaire(:,1) ;
sig_annulaire_1_1 = annulaire(:,2) ;
sig_annulaire_1_2 = annulaire(:,3) ;
temps_annulaire_1_2 = annulaire(:,4) ;
sig_annulaire_1_3 = annulaire(:,5) ;
temps_annulaire_2_1 = annulaire(:,6) ;
sig_annulaire_2_1 = annulaire(:,7) ;
sig_annulaire_2_2 = annulaire(:,8) ; 
temps_annulaire_2_2 = annulaire(:,9) ; 
sig_annulaire_2_3 = annulaire(:,10) ;

% Pouce

pouce = xlsread('Pouce.xlsx') ;
temps_pouce_1_1 = pouce(:,1) ;
sig_pouce_1_1 = pouce(:,2) ;
sig_pouce_1_2 = pouce(:,3) ;
temps_pouce_1_2 = pouce(:,4) ;
sig_pouce_1_3 = pouce(:,5) ;
temps_pouce_2_1 = pouce(:,6) ;
sig_pouce_2_1 = pouce(:,7) ;
sig_pouce_2_2 = pouce(:,8) ; 
temps_pouce_2_2 = pouce(:,9) ; 
sig_pouce_2_3 = pouce(:,10) ;

% Auriculaire (petit doigt)

auriculaire = xlsread('Auriculaire.xlsx') ;
temps_auriculaire_1 = auriculaire(:,1) ;
sig_auriculaire_1 = auriculaire(:,2) ;
sig_auriculaire_2 = auriculaire(:,3) ;
temps_auriculaire_2 = auriculaire(:,4) ;
sig_auriculaire_3 = auriculaire(:,5) ;



%% Main totale 1
% Mise au meme niveau des signaux
sig0_main_1_1 = centre_zero(sig_main_1_1) ;
sig0_main_1_2 = centre_zero(sig_main_1_2) ;
sig0_main_1_3 = centre_zero(sig_main_1_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_main_1_1 = moyenne_glissante(sig0_main_1_1, temps_main_1_1, 0.25) ;
moyenne_glissante_main_1_2 = moyenne_glissante(sig0_main_1_2, temps_main_1_1, 0.10) ;
moyenne_glissante_main_1_3 = moyenne_glissante(sig0_main_1_3, temps_main_1_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_main1 = intensite_signal(moyenne_glissante_main_1_1, moyenne_glissante_main_1_2, moyenne_glissante_main_1_3) ;
doigt_main1 = doigt(int_sig_main1) ;

%% Main totale 2

% Mise au meme niveau des signaux
sig0_main_2_1 = centre_zero(sig_main_2_1) ;
sig0_main_2_2 = centre_zero(sig_main_2_2) ;
sig0_main_2_3 = centre_zero(sig_main_2_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_main_2_1 = moyenne_glissante(sig0_main_2_1, temps_main_2_1, 0.25) ;
moyenne_glissante_main_2_2 = moyenne_glissante(sig0_main_2_2, temps_main_2_1, 0.10) ;
moyenne_glissante_main_2_3 = moyenne_glissante(sig0_main_2_3, temps_main_2_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_main2 = intensite_signal(moyenne_glissante_main_2_1, moyenne_glissante_main_2_2, moyenne_glissante_main_2_3) ;
doigt_main2 = doigt(int_sig_main2) ;

%% Main totale 3

% Mise au meme niveau des signaux
sig0_main_3_1 = centre_zero(sig_main_3_1) ;
sig0_main_3_2 = centre_zero(sig_main_3_2) ;
sig0_main_3_3 = centre_zero(sig_main_3_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_main_3_1 = moyenne_glissante(sig0_main_3_1, temps_main_3_1, 0.25) ;
moyenne_glissante_main_3_2 = moyenne_glissante(sig0_main_3_2, temps_main_3_1, 0.10) ;
moyenne_glissante_main_3_3 = moyenne_glissante(sig0_main_3_3, temps_main_3_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_main3 = intensite_signal(moyenne_glissante_main_3_1, moyenne_glissante_main_3_2, moyenne_glissante_main_3_3) ;
doigt_main3 = doigt(int_sig_main3) ;

%% Annulaire 1

% Mise au meme niveau des signaux
sig0_annulaire_1_1 = centre_zero(sig_annulaire_1_1) ;
sig0_annulaire_1_2 = centre_zero(sig_annulaire_1_2) ;
sig0_annulaire_1_3 = centre_zero(sig_annulaire_1_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_annulaire_1_1 = moyenne_glissante(sig0_annulaire_1_1, temps_annulaire_1_1, 0.25) ;
moyenne_glissante_annulaire_1_2 = moyenne_glissante(sig0_annulaire_1_2, temps_annulaire_1_1, 0.10) ;
moyenne_glissante_annulaire_1_3 = moyenne_glissante(sig0_annulaire_1_3, temps_annulaire_1_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_annulaire1 = intensite_signal(moyenne_glissante_annulaire_1_1, moyenne_glissante_annulaire_1_2, moyenne_glissante_annulaire_1_3) ;
doigt_annulaire1 = doigt(int_sig_annulaire1) ;

%% Annulaire 2

% Mise au meme niveau des signaux
sig0_annulaire_2_1 = centre_zero(sig_annulaire_2_1) ;
sig0_annulaire_2_2 = centre_zero(sig_annulaire_2_2) ;
sig0_annulaire_2_3 = centre_zero(sig_annulaire_2_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_annulaire_2_1 = moyenne_glissante(sig0_annulaire_2_1, temps_annulaire_2_1, 0.25) ;
moyenne_glissante_annulaire_2_2 = moyenne_glissante(sig0_annulaire_2_2, temps_annulaire_2_1, 0.10) ;
moyenne_glissante_annulaire_2_3 = moyenne_glissante(sig0_annulaire_2_3, temps_annulaire_2_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_annulaire2 = intensite_signal(moyenne_glissante_annulaire_2_1, moyenne_glissante_annulaire_2_2, moyenne_glissante_annulaire_2_3) ;
doigt_annulaire2 = doigt(int_sig_annulaire2) ;

%% Pouce 1

% Mise au meme niveau des signaux
sig0_pouce_1_1 = centre_zero(sig_pouce_1_1) ;
sig0_pouce_1_2 = centre_zero(sig_pouce_1_2) ;
sig0_pouce_1_3 = centre_zero(sig_pouce_1_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_pouce_1_1 = moyenne_glissante(sig0_pouce_1_1, temps_pouce_1_1, 0.25) ;
moyenne_glissante_pouce_1_2 = moyenne_glissante(sig0_pouce_1_2, temps_pouce_1_1, 0.10) ;
moyenne_glissante_pouce_1_3 = moyenne_glissante(sig0_pouce_1_3, temps_pouce_1_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_pouce1 = intensite_signal(moyenne_glissante_pouce_1_1, moyenne_glissante_pouce_1_2, moyenne_glissante_pouce_1_3) ;
doigt_pouce1 = doigt(int_sig_pouce1) ;

%% Pouce 2

% Mise au meme niveau des signaux
sig0_pouce_2_1 = centre_zero(sig_pouce_2_1) ;
sig0_pouce_2_2 = centre_zero(sig_pouce_2_2) ;
sig0_pouce_2_3 = centre_zero(sig_pouce_2_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_pouce_2_1 = moyenne_glissante(sig0_pouce_2_1, temps_pouce_2_1, 0.25) ;
moyenne_glissante_pouce_2_2 = moyenne_glissante(sig0_pouce_2_2, temps_pouce_2_1, 0.10) ;
moyenne_glissante_pouce_2_3 = moyenne_glissante(sig0_pouce_2_3, temps_pouce_2_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_pouce2 = intensite_signal(moyenne_glissante_pouce_2_1, moyenne_glissante_pouce_2_2, moyenne_glissante_pouce_2_3) ;
doigt_pouce2 = doigt(int_sig_pouce2) ;

%% Auriculaire

% Mise au meme niveau des signaux
sig0_auriculaire_1 = centre_zero(sig_auriculaire_1) ;
sig0_auriculaire_2 = centre_zero(sig_auriculaire_2) ;
sig0_auriculaire_3 = centre_zero(sig_auriculaire_3) ;

% Moyenne glissante (filtre)
moyenne_glissante_auriculaire_1 = moyenne_glissante(sig0_auriculaire_1, temps_auriculaire_1, 0.25) ;
moyenne_glissante_auriculaire_2 = moyenne_glissante(sig0_auriculaire_2, temps_auriculaire_1, 0.10) ;
moyenne_glissante_auriculaire_3 = moyenne_glissante(sig0_auriculaire_3, temps_auriculaire_2, 0.10) ;

% Intensite des signaux pour chaque mouvement
int_sig_auriculaire1 = intensite_signal(moyenne_glissante_auriculaire_1, moyenne_glissante_auriculaire_2, moyenne_glissante_auriculaire_3) ;
doigt_auriculaire1 = doigt(int_sig_auriculaire1) ;