var express = require("express");
var app = express();
var bodyParser = require('body-parser');
var errorHandler = require('errorhandler');
var methodOverride = require('method-override');
var hostname = process.env.HOSTNAME || 'localhost';
var port = 8080;
var reading = 0;
var db = require('./node_modules/mongoskin').db('mongodb://user:pwd@127.0.0.1:27017/sensorData');


app.get('/sendData', function(req, res){
    var info = req.query;
    var h = info.h;
    var t = info.t;
    var key = info.key;
    if( key !="15974c1d771020e5"){
        res.send("noauth");
        return;
    }  
    console.log(h,t,key);

     info.ts = new Date().getTime();
      db.collection('data').insert(info, function(err3, r3) {
        if (err3) {
          res.send("0");            
        }
         else {       
          res.send("1");
        }   
      }); 

});
app.get('/getData', function(req, res){
    db.collection('data').find().toArray(function(err3, r3) {
    res.writeHead(200, {"Content-Type": "text/plain"});
    res.write(JSON.stringify(r3));
    res.end()
});

});

app.use(methodOverride());
app.use(bodyParser());
app.use(errorHandler());
app.use(express.static(__dirname + '/public'));

console.log("Simple static server listening at http://" + hostname + ":" + port);
app.listen(port);
