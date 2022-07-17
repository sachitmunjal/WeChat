const express = require("express");         
const path = require("path")
const app = express();      

const mongoose = require('mongoose');
const bodyparser = require('body-parser');           // SEE FUNCTION OF BODY-PARSER
mongoose.connect('mongodb://localhost/contactDance',{useNewUrlParser:true,useUnifiedTopology: true });
const port=process.env.PORT || 8000;

// app.use(express.static('static', options))         //doubt


// DEFINE MONGOOSE SCHEMA
const contactSchema = new mongoose.Schema({
    name: String,
    phone: String,
    email: String,
    address: String,
    desc: String,
  });

const Contact = mongoose.model('Contact', contactSchema);


// EXPRESS SPECIFIC STUFF
app.use('/static',express.static(path.join(__dirname,'static')))       // static naam ka folder hum /static endpoint se excess kr skte hai by writing this line
app.use(express.urlencoded({extended:true}))                     // yh line, form ka data, express tak laane me help kr rha hai


// PUG SPECIFIC STUFF
app.set('view engine', 'pug')                      // by this, we set our template engine as pug
app.set('views',path.join(__dirname,'views') )     // set the views directory


// ENDPOINTS
app.get('/',(req,res)=>{
    const params = { }
    res.status(200).render('home.pug',params)
})

app.get('/contact',(req,res)=>{
    const params = { }
    res.status(200).render('contact.pug',params)
})

app.post('/contact',(req,res)=>{
    var myData = new Contact (req.body);             // jo req.body se saamaan aa rha hai, usko extract krke, ek nya object bna rhe hai in Contact collection
    myData.save().then(()=>{                          // by this, hmne data, database me save kr diya
        res.send("This item has been saved to the database.")
    }).catch(()=>{
        res.status(400).send("Item can't be saved to the database.")            // agr data save na ho paaya, to yh response aayega
    })         
    // res.status(200).render('contact.pug')
})

// START THE SERVER
app.listen(port,()=>{
    console.log(`The application started successfully on port ${port}`)
})

// jo bhi file hum browser pr access krna chahte hai(for example - index.js, style.css, images etc), vo static folder me honi chaiye
// server basically html serve krega (and html me hmari .js file and .css file included hongi)
// index.js basically frontend wali js hai and app.js basically backend wali js hai
// jo chrome pr js chlate hai, vo frontend wali js hoti hai