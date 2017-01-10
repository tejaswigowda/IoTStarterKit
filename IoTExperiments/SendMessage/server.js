var nodemailer = require('nodemailer');

// create reusable transporter object using the default SMTP transport
var transporter = nodemailer.createTransport('smtps://test%40foxyninjastudios.com:testuser1234@smtp.gmail.com');

// setup e-mail data with unicode symbols
var mailOptions = {
    from: '"" <test@foxyninjastudios.com>', // sender address
    to: 'tejaswil@gmail.com, 6238065387@txt.att.net', // list of receivers
    subject: 'Test message', // Subject line
    text: 'Hello world ?', // plaintext body
    html: ''
};



var express = require("express");
var app = express();
var bodyParser = require('body-parser');
var errorHandler = require('errorhandler');
var methodOverride = require('method-override');
var hostname = process.env.HOSTNAME || 'localhost';
var port = 8080;
var reading = 0;

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
    mailOptions.subject = "Latest Data";
    mailOptions.text= "Humidity : " + h + "\n Temperature: " + t;

    transporter.sendMail(mailOptions, function(error, info){
      if(error){
          return console.log(error);
      }
      console.log('Message sent: ' + info.response);
      res.send(t + "," + h);
    });

});
app.get('/getState', function(req, res){
    res.writeHead(200, {"Content-Type": "text/plain"});
      res.write(String(reading));
        res.end()

});

app.use(methodOverride());
app.use(bodyParser());
app.use(errorHandler());

console.log("Simple static server listening at http://" + hostname + ":" + port);
app.listen(port);
