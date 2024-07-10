function toCamelCase(str) {
    let newStr = "";
    if (str) {
        let wordArr = str.split(/[-_]/g);
        for (let i in wordArr) {
            if (i > 0) {
                newStr += wordArr[i].charAt(0).toUpperCase() + wordArr[i].slice(1);
            } else {
                newStr += wordArr[i];
            }
        }
    }
    console.log(newStr);
    return newStr;
}


toCamelCase("the-stealth-warrior");