import os
import time
from pathlib import Path
from bs4 import BeautifulSoup

def preProcessSourceCode(sourceCode):
    return sourceCode

def getSourceCode(pageSoup):
    pres = pageSoup.find_all('pre')
    if pres[0].has_attr("id"):
        if pres[0]["id"] == "program-source-text":
            return pres[0].get_text()
    return ""

def generateSourceCodeStatistics(contest_id, standings, participant_id, submission_id):
    contest_id_dir = "Contest"+contest_id
    f = open(contest_id_dir+"/Standings"+standings+"/"+participant_id+"_"+submission_id, 'r')
    source_code_page = f.read()
    f.close()

    source_code_soup = BeautifulSoup(source_code_page, 'html.parser')
    trs = source_code_soup.find_all('tr')
    tds = trs[1].find_all('td')

    ### extract statistics
    submissionid = tds[0].get_text().lstrip().split('\n')[0]
    language = tds[3].get_text().lstrip().split('\n')[0]
    time = tds[5].get_text().lstrip().split('\n')[0].split(' ')[0] ### in ms
    memory = tds[6].get_text().lstrip().split('\n')[0].split(' ')[0] ### in KB

    ### extract source code
    contest_id_dir = "Contest"+contest_id
    codes_dir = contest_id_dir+"/Standings"+standings+"/CODES"
    os.makedirs(codes_dir, exist_ok=True)
    code_file = Path(codes_dir+"/"+participant_id+"_"+submission_id)
    if not code_file.is_file():
        source_code = getSourceCode(source_code_soup)

        if "c++" in language.lower():
            fw = open(str(code_file)+".cpp",'w')
        elif "java" in language.lower():
            fw = open(str(code_file)+".java",'w')
        elif "pypy" in language.lower():
            fw = open(str(code_file)+".py",'w')
        else:
            fw = open(str(code_file),'w')

        fw.write(source_code)
        fw.close()
    else:
        print("Code already extracted...")

    return (submissionid,language, time, memory)

def generateStandingStatistics(contest_id, problem_ids, topk=5):
    contest_id_dir = "Contest"+contest_id
    fw = open(contest_id_dir+"/standings_statistics", 'w') ## write to statistics file
    fw2 = open(contest_id_dir+"/problem_statistics", 'w') ## problem specific statistics file

    header = "ParticipantID\tColor\tRank\tCountry"
    for i in range(len(problem_ids)):
        problemID = "Problem"+str(i+1)
        header += ("\t"+problemID+"_id\t"+problemID+"_memory\t"+problemID+"_time\t"+problemID+"_language")
    fw.write(header+"\n")

    fw2.write("SubmissionID\tProblem_index\tParticipant_country\tParticipant_color\tLanguage\tTime\tMemory\n")

    for i in range(topk):
        f = open(contest_id_dir+"/standings_"+str(i+1), 'r')
        standing_page = f.read()
        f.close()

        page_soup = BeautifulSoup(standing_page, 'html.parser')
        trs = page_soup.find_all('tr')

        ## the first tr is redundant
        for participant in range(1,201):
            line = ""
            p = trs[participant]
            participant_id = p['participantid']
            tds = p.find_all('td')

            line += participant_id
            rank = tds[0].get_text().lstrip().split('\n')[0]
            country = '-'
            color = '-'
            if len(tds[1].find_all('img')) != 0:
                country = tds[1].find_all('img')[0]['title']
            if len(tds[1].find_all('a')) != 0:
                color = tds[1].find_all('a')[0]['class'][1].split('-')[1]
            line += ('\t' + color + '\t' + rank + '\t' + country)

            for pid in problem_ids:
                found = False
                for elem in tds: ## get if problem is solved
                    if elem.has_attr('problemid'):
                        problem_id = elem['problemid']
                        if problem_id == pid:
                            found = True
                            if elem.has_attr('acceptedsubmissionid'):
                                accepted_submission_id = elem['acceptedsubmissionid']
                                submissionid, langauge, time, memory = generateSourceCodeStatistics(contest_id, str(i+1), participant_id, accepted_submission_id)
                                line += ('\t' + submissionid+"\t"+memory+"\t"+time+"\t"+langauge)
                                fw2.write(participant_id+"_"+accepted_submission_id+"\t"+str(problem_ids.index(pid)+1)+"\t"+country+"\t"+color+"\t"+langauge+"\t"+time+"\t"+memory+"\n")
                            else:
                                line += ('\t' + "NO\t-\t-\t-")

                if not found:
                    line += ('\t' + "-\t-\t-\t-")
            fw.write(line+"\n")

    fw.close()
    fw2.close()

### download Data for contest 1245
contest_id = "1245"
problemA_id = "456074"
problemB_id = "456075"
problemC_id = "456076"
problemD_id = "456077"
problemE_id = "456078"
problemF_id = "456079"
generateStandingStatistics(contest_id, [problemA_id, problemB_id, problemC_id, problemD_id, problemE_id, problemF_id])
print("Processed "+contest_id+"...")

### download Data for contest 1236
contest_id = "1236"
problemA_id = "442393"
problemB_id = "442394"
problemC_id = "442395"
problemD_id = "442396"
problemE_id = "442397"
problemF_id = "442398"
generateStandingStatistics(contest_id, [problemA_id, problemB_id, problemC_id, problemD_id, problemE_id, problemF_id])
print("Processed "+contest_id+"...")

# ### download Data for contest 1243
contest_id = "1243"
problemA_id = "461411"
problemB_id = "461412"
problemC_id = "461413"
problemD_id = "461414"
problemE_id = "461415"
problemF_id = "461416"
generateStandingStatistics(contest_id, [problemA_id, problemB_id, problemC_id, problemD_id, problemE_id, problemF_id])
print("Processed "+contest_id+"...")

# ### download Data for contest 1244
contest_id = "1244"
problemA_id = "438880"
problemB_id = "438881"
problemC_id = "438882"
problemD_id = "438883"
problemE_id = "438884"
problemF_id = "438885"
problemG_id = "438886"
generateStandingStatistics(contest_id, [problemA_id, problemB_id, problemC_id, problemD_id, problemE_id, problemF_id, problemG_id])
print("Processed "+contest_id+"...")

# ### download Data for contest 1248
contest_id = "1248"
problemA_id = "445483"
problemB_id = "445264"
problemC_id = "445265"
problemD_id = "445481"
problemE_id = "445266"
problemF_id = "445267"
problemG_id = "445268"
generateStandingStatistics(contest_id, [problemA_id, problemB_id, problemC_id, problemD_id, problemE_id, problemF_id, problemG_id])
print("Processed "+contest_id+"...")
