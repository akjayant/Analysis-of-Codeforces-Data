import os
from pathlib import Path

import requests
from bs4 import BeautifulSoup

contest_id = "" #"1245"
problemA_id = "" #"456074"
problemB_id = "" #"456075"
problemC_id = "" #"456076"

if contest_id == "":
    print("Contest ID is blank")
    exit(1)

contest_id_dir = "Contest"+contest_id
contest_url = "https://codeforces.com/contest/"+contest_id
os.makedirs(contest_id_dir, exist_ok=True)

topk = 5 ### download the top k standing list pages
for i in range(topk):
    my_file = Path(contest_id_dir+"/standings_"+str(i+1))
    if my_file.is_file():
        print("Standings "+str(i+1)+" already downloaded.")
        continue

    page = requests.get(contest_url+"/standings/page/"+str(i+1))
    assert page.status_code == 200

    f = open(contest_id_dir+"/standings_"+str(i+1), 'w')
    f.write(page.text)
    f.close()

for i in range(1):
    f = open(contest_id_dir+"/standings_"+str(i+1), 'r')
    page = f.read()
    f.close()

    page_soup = BeautifulSoup(page, 'html.parser')
    trs = page_soup.find_all('tr')

    ## the first tr is redundant
    for participant in range(1,201):
        p = trs[participant]
        participant_id = p['participantid']
        print(participant, participant_id)
        tds = p.find_all('td')
        for elem in tds:
            if elem.has_attr('problemid'):
                problem_id = elem['problemid']
                if problem_id == problemA_id or problem_id == problemB_id or problem_id == problemC_id:
                    accepted_submission_id = "-1"
                    if elem.has_attr('acceptedsubmissionid'):
                        accepted_submission_id = elem['acceptedsubmissionid']
                    title = elem['title']
                    print(problem_id,accepted_submission_id,title)
        print()
