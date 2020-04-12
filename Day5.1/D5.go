package main

import(
  "fmt"
  "io/ioutil"
  "strconv"
  "strings"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func main(){
  var linesInt = []int{}

  data, err := ioutil.ReadFile("D5.txt")
  check(err)
  fmt.Print(string(data))
  dataString := strings.TrimSuffix(string(data), "\r\n")

  lines := strings.Split(dataString, ",")
  fmt.Println(lines)

  for i := 0;  i < len(lines); i++ {
      j, err := strconv.Atoi(lines[i])
      if err != nil {
          panic(err)
      }
      linesInt = append(linesInt, j)
  }

  linesInt[1] = 12
  linesInt[2] = 2

  fmt.Println(linesInt)

  for i := 0; i < len(linesInt); i=i+4 {
    if linesInt[i] == 1 {
      linesInt[linesInt[i+3]] = linesInt[linesInt[i+1]] + linesInt[linesInt[i+2]]
    } else if linesInt[i] == 2 {
      linesInt[linesInt[i+3]] = linesInt[linesInt[i+1]] * linesInt[linesInt[i+2]]
    } else {
      break
    }
  }

  fmt.Println(linesInt[0])

}
