'''
Lecture6GeneFind.py
Author: Rhonda Hoenigman
University of Colorado, Boulder
Fall, 2015
'''

'''
Think about the algorithm first.
'''
#declare variable
DNA = "AAGTCATGCCCGGGTTCGGA"
#use find to identify starting codon in the DNA
i = DNA.find("ATG")
#i is an index, a new string can be created by starting at that index
#and grabbing everything to the end
gene = DNA[i:]
#use count on the gene string to count the instances of the GGA and GGG
GGA = gene.count("GGA")
GGG = gene.count("GGG")

print gene
print "Number is ", GGA + GGG
