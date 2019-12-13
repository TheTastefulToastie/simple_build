// @Compile node test.js Dave

function open_pod_bay_doors(name) {
  console.log(`I'm sorry ${name}, I'm afraid I can't do that.`);
}

open_pod_bay_doors(process.argv[2]);
