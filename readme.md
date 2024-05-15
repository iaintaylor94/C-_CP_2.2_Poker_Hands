# Programming Challenges C++
## Problem 2.2 Poker Hands[^1]
### Problem description
This program determines the best hand possible for two decks of cards, and returns the winner or whether there was a tie.

The cards contain the values (lowes to highest):
1. 2                                      
2. 3                                          
3. 4                                       
4. 5                                        
5. 6                                             
6. 7                                              
7. 8                                                  
8. 9                                             
9. J (Jack)                                          
10. Q (Queen)                                          
11. K (King)                                            
12. A (Ace)                                         

The cards are of suit:
1. C (Clubs)
2. D (Diamonds)
3. H (Hearts)
4. S (Spades)                                      

The rank of the hands are as below (lowest to highest):
1. High card 
2. Pair
3. Two Pairs
4. Three of a kind
5. Straight (5 cards with consecutive values - ranked by highest card)
6. Flush (5 cards of same suit - ranked by highest card)
7. Full House (3 of kind + Pair - ranked by value of 3 of kind)
8. Four of a kind
9. Straight flush (straight + flush - ranked by highest card)

The input consists of:
1. 10 value/suit pairs (WHITE/BLACK)
2. Terminates on EOF


The output is either:
1. The string "White wins."
2. The string "Black wins."
3. The string "Tie."


### Example 
>**Input**                                                                 
>2H 3D 5S 9C KD 2C 3H 4S 8C AH                                                
>2H 4S 4C 2D 4H 2S 8S AS QS 3S
>2H 3D 5S 9C KD 2C 3H 4S 8C KH                                              
>2H 3D 5S 9C KD 2D 3H 5C 9S KH                                                                                                                       

>**Output**                                         
>White wins.                                       
>Black wins.
>Black wins.
>Tie.                                                


### Problem solution
1. Read input
2. if (EOF) exit program
3. else
   1. Construct hands
   2. Calculate rank of hands
   3. Determine winner
   4. Print winner/tie
   5. GOTO step 1


**Optional:**
1. Function overloading (cout / ofstream)
2. Operator overloading (<< / >> / ++)
3. Templates


### Bug Checklist
- [1] NA

[^1]: Programming Challenges By S.Skienna and M.Revilla, page 43