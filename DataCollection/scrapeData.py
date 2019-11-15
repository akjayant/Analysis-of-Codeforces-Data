import os
import time
from pathlib import Path

import requests
from bs4 import BeautifulSoup

def downloadSourceCodeURL(url):
    downloadSuccess = False

    while not downloadSuccess:
        try:
            source_code_page = requests.get(url)
            assert source_code_page.status_code == 200
            downloadSuccess = True
            print("Sleeping...")
            time.sleep(3) ## wait after every download to give breathing time
        except requests.exceptions.ConnectionError:
            print("Connection refused")
            print("Sleeping for 30 seconds...")
            time.sleep(30) ## if connection error, wait longer

        if downloadSuccess:
            if "program-source-text" not in source_code_page.text: ## check validity
                downloadSuccess = False
            else:
                break

    return source_code_page

def downloadContest(contest_id, problem_ids, topk=5):
    if contest_id == "":
        print("Contest ID is blank")
        return

    for problem_id in problem_ids:
        if problem_id == "":
            print("One of the problem ids is empty")
            return

    contest_id_dir = "Contest"+contest_id
    contest_url = "https://codeforces.com/contest/"+contest_id
    os.makedirs(contest_id_dir, exist_ok=True)

    for i in range(topk): ## downloading standing pages
        my_file = Path(contest_id_dir+"/standings_"+str(i+1))
        if my_file.is_file():
            print("Standings "+str(i+1)+" already downloaded.")
            continue

        page = requests.get(contest_url+"/standings/page/"+str(i+1))
        assert page.status_code == 200

        f = open(contest_id_dir+"/standings_"+str(i+1), 'w')
        f.write(page.text)
        f.close()

    for i in range(topk):
        f = open(contest_id_dir+"/standings_"+str(i+1), 'r')
        page = f.read()
        f.close()

        page_soup = BeautifulSoup(page, 'html.parser')
        trs = page_soup.find_all('tr')

        standings_dir = contest_id_dir + "/Standings"+str(i+1)
        os.makedirs(standings_dir, exist_ok=True)

        ## the first tr is redundant
        for participant in range(1,201):
            p = trs[participant]
            participant_id = p['participantid']
            print(participant, participant_id)
            tds = p.find_all('td')
            for elem in tds:
                if elem.has_attr('problemid'):
                    problem_id = elem['problemid']
                    if problem_id in problem_ids:
                        accepted_submission_id = "-1"
                        if elem.has_attr('acceptedsubmissionid'):
                            accepted_submission_id = elem['acceptedsubmissionid']
                        title = elem['title']
                        print(problem_id,accepted_submission_id,title)

                        ## download source code
                        if accepted_submission_id != "-1":
                            source_code_file = Path(standings_dir+"/"+participant_id+"_"+accepted_submission_id)
                            if source_code_file.is_file():
                                print("Source code for submissionID "+accepted_submission_id+" for participant "+participant_id+" already downloaded.")
                                continue

                            source_code_page = downloadSourceCodeURL(contest_url+"/submission/"+accepted_submission_id)

                            f = open(standings_dir+"/"+participant_id+"_"+accepted_submission_id, 'w')
                            f.write(source_code_page.text)
                            f.close()
            print()

### download Data for contest 1245
# contest_id = "1245"
# problemA_id = "456074"
# problemB_id = "456075"
# problemC_id = "456076"
# downloadContest(contest_id, [problemA_id, problemB_id, problemC_id])

### download Data for contest 1245
# contest_id = "1236"
# problemA_id = "442393"
# problemB_id = "442394"
# problemC_id = "442395"
# downloadContest(contest_id, [problemA_id, problemB_id, problemC_id])
#
# ### download Data for contest 1245
# contest_id = "1243"
# problemA_id = "461411"
# problemB_id = "461412"
# problemC_id = "461413"
# downloadContest(contest_id, [problemA_id, problemB_id, problemC_id])
