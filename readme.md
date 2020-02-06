### Problem Statement: 
To analyze correlation between coding style and cod-
ing proficiency, and whether coding styles show regional variations.
Data sets: Data for top 1000 performers in 5 Division-2 contests was scraped
from Codeforces, a competitive coding platform. Total number of datapoints
is ∼ 18000 codes.
### Abstract: 
An important employability indicator in software field is coding
proficiency. Codeforces is a popular platform enabling one to practice coding
skills through regular contests. It also assigns a proficiency rating to every
user based on contest performances. Performing such an analysis can help
in giving better feedback to novices in what structure they should use and
which APIs they should use more often.
### Approach: 
Approaches taken in increasing complexity:
a) Extracting simple features like function calls, variables declared, num-
ber of macros etc.
b) Using tree edit distance between abstract syntax trees of two different
codebases to identify coding style similarity.
c) Extracting features: low level- tokens used, and high level- code struc-
ture via doc2vec embedding of the abstract syntax tree.
Conclusion: We analyze correlation between coding style and coding pro-
ficiency and whether coding styles varies across regions. We are able to find
coding style difference across regions but are unable to find any significant
correlation between coding proficiency and coding style. We also provide
some possible explanations of how the features used help in determining the
correlations under study.
### References:
1. Zhang, Kaizhong, and Dennis Shasha. ”Simple fast algorithms for
the editing distance between trees and related problems.” SIAM journal on
computing 18.6 (1989): 1245-1262.
2. Lau, Jey Han, and Timothy Baldwin. ”An empirical evaluation of
doc2vec with practical insights into document embedding generation.” arXiv
preprint arXiv:1607.05368 (2016).
### Files
1. Data Collected can be found in ./Data
2. Files related to primitive features are in PrimitiveApproach
3. Files related to tree similarity are in TreeSimilarityApproach
4. Files related to Doc2Vec and Tokenization and notebook having model on Country vs Coding Style
