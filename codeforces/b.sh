# str01="codeforces_"
# str02=$1
# str03=".cpp"

# g++ --std=c++17  ${str01}${str02}${str03}

dirfile=$(ls -lt | awk 'NR==2 {print $9}')
g++ --std=c++17  ${dirfile} 
