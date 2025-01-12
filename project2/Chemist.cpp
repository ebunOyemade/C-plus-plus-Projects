/*****************************************
** File:    Chemist.cpp
** Project: CMSC 202 Project 2, Spring 2022
** Author:  Ebun Oyemade
** Date:    3/15/22
** Section: 54
** E-mail:  eoyemad1@gl.umbc.edu 
**
** This file contains the the functions of the Chemist class for project 2.
** This file has functions that help retrieve data and checks for  prerequesites for certain actions.
** 
** 
** 
**
**
***********************************************/

#include "Chemist.h"
using namespace std;

//Chemist
//default constructor, sets name to beaker
Chemist::Chemist(){
  m_myName = "Beaker";
  m_numSubstances = 0;
}

//Chemist(string)
//sets m_numSubstances to zero
Chemist::Chemist(string name){
  m_myName = name;
  m_numSubstances = 0;
}

//GetName
//returns m_myName
string Chemist::GetName(){
  return m_myName;
}

//SetName
//take name and makes m_myName equal it
void Chemist::SetName(string name){
  m_myName = name;
}

//CheckSubstance
//takes a Substances returns whether a item is on the list
int Chemist::CheckSubstance(Substance sub){
    for(int i = 0; i < PROJ2_SIZE; i++){
      if(sub.m_name == m_mySubstances[i].m_name){
	return i;
      }
    }
    return -1;
    
}

//AddSubstance
//takes a Substance and adds it to the m_mySubstances and increments numSubstances
void Chemist::AddSubstance(Substance sub){
  m_mySubstances[m_numSubstances].m_name  = sub.m_name;
  m_mySubstances[m_numSubstances].m_type = sub.m_type;
  m_mySubstances[m_numSubstances].m_formula = sub.m_formula;
  m_mySubstances[m_numSubstances].m_substance1 = sub.m_substance1;
  m_mySubstances[m_numSubstances].m_substance2 = sub.m_substance2;
  m_mySubstances[m_numSubstances].m_quantity = 0;
  m_numSubstances ++; 
  return;
}

//IncementQuantity
//takes Substance and finds location in m_mySubstances to increment quantity
void Chemist::IncrementQuantity(Substance sub){
  for(int i = 0; i < PROJ2_SIZE; i++){
    if(sub.m_name == m_mySubstances[i].m_name){
      m_mySubstances[i].m_quantity += 1;
    }
  }
  return;
}

//DecrementQuantity
//takes Substances and finds location in m_mySubstancs to decrement
bool Chemist::DecrementQuantity(Substance sub){
  if (sub.m_quantity > 1){
    for(int i = 0; i < PROJ2_SIZE; i++){
      if(sub.m_name == m_mySubstances[i].m_name){
      m_mySubstances[i].m_quantity -= 1;
      }
    }

    return true;
    
  }else{
    
    return false;
  }
}

//CheckQuantity
//Takes two substances and returns true if both have quatities over 1
bool Chemist::CheckQuantity(Substance sub1, Substance sub2){
  if((sub1.m_quantity > 1)&&(sub2.m_quantity > 1)){
    
    return true;
  }else{
    
    return false;
  }
}

//GetSubstance
//Returns a Substance given a number
Substance Chemist::GetSubstance(int num){
  return m_mySubstances[num];
}

//GetTotalSubstance
//Returns the total number of substances with quantities more than 0
int Chemist::GetTotalSubstances(){
  int count = 0;
  
  for(int i = 0; i < PROJ2_SIZE; i++){
    if(m_mySubstances[i].m_quantity > 0){
      
      count += 1;
    }
  }
  
  return count;
}
