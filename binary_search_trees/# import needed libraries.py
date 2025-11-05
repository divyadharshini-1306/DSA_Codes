# import needed libraries
import requests
from bs4 import BeautifulSoup
import pandas as pd
import matplotlib.pyplot as plt


# we are accessing github statistics
url = "https://github.com/trending"

# use request module to access
response = requests.get(url)
# status of response. 200 is OK for us
print(response)

# parse the data with beautifulsoup library
soup = BeautifulSoup(response.text, "html.parser")
#print(soup)

# create a array to hold needed data
repos = []

# our needed data is nested inside html
# identify the html element and parse it
for repo in soup.find_all("article", class_="Box-row"):
    # get name of repository
    name = repo.h2.a.get_text(strip=True)

    # star rating parsing. in case of no star, we set it to 0
    stars = repo.find("a", attrs={"href": lambda x: x and x.endswith("/stargazers")})
    stars = stars.get_text(strip=True) if stars else "0"

    # get programming language. if not available we set as unknown
    lang = repo.find("span", itemprop="programmingLanguage")
    lang = lang.get_text(strip=True) if lang else "Unknown"

    # append the data to array. now it is array of array
    repos.append([name, stars, lang])

#print(repos)

# Step 3: Store into CSV
df = pd.DataFrame(repos, columns=["Repository", "Stars", "Language"])
#uncomment to see full data
#pd.set_option('display.max_rows', None)
#pd.set_option('display.max_columns', None)
#print(df)

# Step 4: Preprocessing
df["Stars"] = df["Stars"].str.replace(",", "").astype(int)  # convert stars to int
df["Language"].fillna("Unknown", inplace=True)
df.drop_duplicates(inplace=True)

# task1:send output to csv file
df.to_csv("github_trending.csv", index=False)

# task2: create basic statistics and additional data for other descriptive statistics
# Basic statistics from describe()
summary = df["Stars"].describe()

# Extra statistics
extra_stats = pd.Series({
    "mode": df["Stars"].mode()[0],
    "variance": df["Stars"].var(),
    "skewness": df["Stars"].skew(),
    "kurtosis": df["Stars"].kurt()
})

# Combine
stats_table = pd.concat([summary, extra_stats])

# Convert to DataFrame for nice formatting
stats_table = stats_table.to_frame(name="Value")

# Format with commas and 2 decimals
stats_table["Value"] = stats_table["Value"].apply(lambda x: f"{x:,.2f}")

print("\n📊 Descriptive Statistics for Stars:\n")
print(stats_table)