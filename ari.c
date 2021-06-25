#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_characters(string s) {
  int l = strlen(s);
  int alpha_num = 0;
  for (int i=0; i<l; i++) {
   if (isalnum(s[i])) {
     alpha_num ++;
     }
  }
  return alpha_num;
}

int count_words(string s) {
  int num_spaces = 0;
  for (int i=0; i<strlen(s); i++) {
    if (s[i] == ' ') {
      num_spaces ++;
    }
  }
  return num_spaces;
}

int count_sentences(string s) {
  int num_sentences = 0;
  for (int i=0; i<strlen(s); i++) {
    if (s[i] == '.' || s[i] == '!' || s[i] == '?')
      	    num_sentences++;
   }
  return num_sentences;
}    
  
string ari(string s) {
  string grades[] = {"Kindergarten","First/Second Grade","Third Grade","Fourth Grade","Fifth Grade","Sixth Grade","Seventh Grade","Eighth Grade","Ninth Grade","Tenth Grade","Eleventh Grade","Twelfth grade","College student","Professor"};
  int characters = count_characters(s);
  int words = count_words(s);
  int sentences = count_sentences(s);
  float score, W , C;
    C = (float)characters/words;
    W = (float)words/sentences;
    score = 4.71 * C + 0.5 * W - 21.43;
  int i = (int)ceilf(score);
  return grades[i-1];
}
