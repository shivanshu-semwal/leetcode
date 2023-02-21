function getnext() {
  document.querySelector("#__next > div > div > div.grid.grid-cols-4.gap-4.md\\:grid-cols-3.lg\\:grid-cols-4.lg\\:gap-6 > div.col-span-4.z-base.md\\:col-span-2.lg\\:col-span-3 > div:nth-child(7) > div.mt-4.flex.flex-col-reverse.items-center.md\\:flex-row.md\\:justify-between > nav > button:nth-child(10)").click()
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function getlist() {
  s = ''
  for (start = 1; start <= 24; start++) {
    var jq = document.createElement('script');
    jq.src = "https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js";
    document.getElementsByTagName('head')[0].appendChild(jq);
    a = $("[role=rowgroup]")[0]; // main grid
    n = a.childNodes.length
    for (i = 0; i < n; i++) {
      aa = a.childNodes[i]
      t = aa.childNodes[1]
      tt = t.getElementsByTagName("a")[0]
      s += "- [" + tt.innerHTML + "]"
      s += "(https://leetcode.com" + tt.getAttribute("href") + ")"

      s += " " + aa.childNodes[4].getElementsByTagName("span")[0].innerHTML + " "

      txt = aa.childNodes[0].innerHTML
      if (!txt.includes("M4 12a1")) {
        s += "Premium"
      }


      s += "\n"
    }
    getnext();
    await sleep(5000);
  }
  console.log(s)
}

getlist();