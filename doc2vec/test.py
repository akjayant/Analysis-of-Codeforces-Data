#python example to infer document vectors from trained doc2vec model
import gensim.models as g
import codecs

#parameters
model="model.bin"
output_file="test_vectors.txt"
test = "include directive file include directive file include directive file include directive file using namespace name define directive macro name value define directive macro name value define directive macro name value define directive macro name value typedef type name name name decl_stmt decl type specifier name name init expr literal type number operator literal type number function type name name parameter_list block decl_stmt decl type name name expr_stmt expr call name argument_list argument expr literal type string argument expr operator name while condition expr name operator block decl_stmt decl type name name decl type ref prev name expr_stmt expr call name argument_list argument expr literal type string argument expr operator name argument expr operator name if condition expr call name argument_list argument expr name argument expr name operator literal type number then block expr_stmt expr call name argument_list argument expr literal type string else block expr_stmt expr call name argument_list argument expr literal type string return expr literal type number"


#inference hyper-parameters
start_alpha=0.01
infer_epoch=1000

#load model
m = g.Doc2Vec.load(model)
test_docs = test.strip().split()
# print(test_docs)

# infer test vectors
output = open(output_file, "w")
output.write( " ".join([str(x) for x in m.infer_vector(test_docs, alpha=start_alpha, steps=infer_epoch)]) + "\n" )
output.flush()
output.close()
