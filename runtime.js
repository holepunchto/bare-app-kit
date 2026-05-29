const { type } = require('bare-build/constants')

const { EXECUTABLE } = type

require.asset = require('require-asset')

const prebuilds = {}

exports.prebuilds = prebuilds

prebuilds['darwin-x64'] = () => {
  return {
    type: EXECUTABLE,
    path: require.asset('./prebuilds/darwin-x64/bare', __filename),
    dependencies: []
  }
}

prebuilds['darwin-arm64'] = () => {
  return {
    type: EXECUTABLE,
    path: require.asset('./prebuilds/darwin-arm64/bare', __filename),
    dependencies: []
  }
}
