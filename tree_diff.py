import zss    #pip install zss
import xml.etree.ElementTree as ET
def get_children(node):
    my_children = [child for child in node]
    return my_children

    
def get_label(node):
    my_label = [child.tag for child in node]
    return my_label
def xmltree_dist(xml_1,xml_2):
    d  = zss.simple_distance(ET.parse(xml_1).getroot(),ET.parse(xml_2).getroot(),get_children,get_label)
    return d
#pass path_to_xmls
xml_1 = '/home/ashish-j/workspace/Data_Analytics/Project/project_local_work/E0259_Project/Data/Contest1236/all_xml/29091733_62799939.xml'
xml_2 = '/home/ashish-j/workspace/Data_Analytics/Project/project_local_work/E0259_Project/Data/Contest1236/all_xml/29087161_62785968.xml'
d=xmltree_dist(xml_1,xml_2)
print(d)
