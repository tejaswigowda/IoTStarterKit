var http = require("http");

function callback (req, res) { // req -> request object; res -> response object
   res.writeHead(200, {'Content-Type': 'text/plain'}); // send response header
   res.end("hello world"); // send response body
}

var server = http.createServer(callback) // create an http server
server.listen(8080, "127.0.0.1"); // make server listen to port 8080


console.log("Server running at: "+ "http://127.0.0.1:8080");
