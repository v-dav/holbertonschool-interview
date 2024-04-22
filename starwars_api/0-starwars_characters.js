#!/usr/bin/node

const { exit } = require('process');
const request = require('request');

// Usage validation
if (process.argv.length !== 3) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>')
  exit(1);
}

const movieId = process.argv[2];

if (!/^\d+$/.test(movieId)) {
  console.error('The movie ID should be a valid integer');
  exit(1);
}

const requestUrl = 'https://swapi-api.hbtn.io/api/films/' + movieId;

// Helper function for promises
function makeRequest(url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error || response.statusCode !== 200) {
        reject(error || new Error(`Request failed with status code ${response.statusCode}`));
      } else {
        resolve(JSON.parse(body));
      }
    })
  })
}

//The main function
async function getCharactersNames() {
  try {
    const filmData = await makeRequest(requestUrl);
    const charactersUrls = filmData.characters;
    for (const charactersUrl of charactersUrls) {
      const characterData = await makeRequest(charactersUrl);
      console.log(characterData.name)
    }
  } catch (err) {
    console.error('Error:', err.message);
    exit(1);
  }
}

getCharactersNames();
