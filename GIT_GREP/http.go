package main

import (
	"fmt"
	// "github.com/yhat/scrape"
	// "golang.org/x/net/html"
	// "golang.org/x/net/html/atom"
	"encoding/base64"
	"encoding/json"
	"io/ioutil"
	"net/http"
	"os"
)

//#TODO Boyer–Moore string search algorithm

type json_response struct {
	records []record
}

type record struct {
	Url  string `json:"url"`
	Name string `json:"name"`
}

func main() {
	user := "ivinpolosony"
	repo_name := "C-code"

	url := "https://api.github.com/repos/" + user + "/" + repo_name + "/contents"

	resp, err := http.Get(url)
	if err != nil {
		os.Exit(0)
	}
	json_resp, _ := ioutil.ReadAll(resp.Body)

	textBytes := []byte(json_resp)

	var mess []map[string]interface{}
	json.Unmarshal(textBytes, &mess)
	fmt.Println(mess)
	for k, v := range mess {
		fmt.Println(k)
		fmt.Println(v["url"])
	}
	resp.Body.Close()

	code_url := "https://api.github.com/repos/ivinpolosony/C-code/contents/simple_csv.cc?ref=master"
	resp1, _ := http.Get(code_url)
	code_resp, _ := ioutil.ReadAll(resp1.Body)
	var code_content map[string]interface{}
	json.Unmarshal([]byte(code_resp), &code_content)
	fmt.Println(code_content["content"])
	data, err := base64.StdEncoding.DecodeString(code_content["content"].(string))
	fmt.Println(string(data))
}
