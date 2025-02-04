import jsonfile from "jsonfile";
import moment from "moment";
import simpleGit from "simple-git";
const path="./data.json";
const markCommit=(x,y)=>{
const date=moment()
  .subtract(1,"y")
  .add(1,"d")
  .add(x,"w")
  .add(y,"d")
  .format();
const data={
  date:date,
};
jsonfile.writefile(path,data,()=>{
  simpleGit().add([path]).commit(date,{'--date':date}).push();
});
};
